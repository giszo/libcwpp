/*
 * Window manager library for console applications.
 *
 * Copyright (c) 2011  Peter Hajdu, Zoltan Kovacs
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <assert.h>

#include <libcwpp/window/BufferedWindow.hpp>

#include "BufferedStream.hpp"
#include "../util/StringUtils.hpp"

using libcwpp::window::BufferedWindow;

BufferedWindow::BufferedWindow(libcwpp::core::Size size, libcwpp::core::Canvas* canvas)
    : Window(size, canvas), m_lastLineClosed(false)
{
}


BufferedWindow::~BufferedWindow()
{
  for (std::deque<libcwpp::stream::Stream*>::const_iterator it = m_streams.begin();
        it != m_streams.end();
        ++it)
    delete *it;
}


void BufferedWindow::addText(const std::string& buffer)
{
    if (buffer.empty())
        return;

    TLines lines = libcwpp::util::StringUtils::tokenize(buffer, "\n");
    assert(!lines.empty());

    {
        cppg::thread::MutexGuard l(m_mutex);

        if (!m_lines.empty() && !m_lastLineClosed)
        {
            m_lines.back() += lines.front();
            lines.pop_front();
        }

        for (TLines::const_iterator it = lines.begin(); it != lines.end(); ++it)
            m_lines.push_back(*it);

        m_lastLineClosed = (buffer[buffer.size() - 1] == '\n');
    }

    invalidate();
}

libcwpp::stream::Stream& BufferedWindow::createStream(bool autoFlush)
{
    libcwpp::stream::Stream* stream = new BufferedStream(this, autoFlush);
    m_streams.push_back(stream);
    return *stream;
}

void BufferedWindow::paint(void)
{
    int y = 0;

    m_canvas->clear();

    {
        cppg::thread::MutexGuard l(m_mutex);

        for (TLines::const_iterator it = m_lines.begin(); it != m_lines.end(); ++it)
            m_canvas->print(0, y++, "%s", it->c_str());
    }
}
