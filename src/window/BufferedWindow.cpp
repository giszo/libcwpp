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

namespace libcwpp
{
namespace window
{

BufferedWindow::BufferedWindow(libcwpp::core::Size size)
    : Window(size), m_lastLineClosed(false)
{
}

void BufferedWindow::addText(const std::string& buffer)
{
    if (buffer.empty())
    {
        return;
    }

    std::deque<std::string> lines = libcwpp::util::StringUtils::tokenize(buffer, "\n");
    assert(!lines.empty());

    if (!m_lines.empty() && !m_lastLineClosed)
    {
        m_lines.back() += lines.front();
        lines.pop_front();
    }

    for (std::deque<std::string>::const_iterator it = lines.begin();
         it != lines.end();
         ++it)
    {
        m_lines.push_back(*it);
    }

    m_lastLineClosed = (buffer[buffer.size() - 1] == '\n');

    invalidate();
}

libcwpp::stream::Stream& BufferedWindow::createStream(void)
{
    libcwpp::stream::Stream* stream = new BufferedStream(this);
    m_streams.push_back(stream);
    return *stream;
}

void BufferedWindow::paint(void)
{
    int y = 0;

    clear();

    for (std::deque<std::string>::const_iterator it = m_lines.begin();
         it != m_lines.end();
         ++it)
    {
        const std::string& line = *it;
        print(0, y++, "%s", line.c_str());
    }
}

} /* namespace window */
} /* namespace libcwpp */
