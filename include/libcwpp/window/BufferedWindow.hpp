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

#ifndef LIBCWPP_BUFFEREDWINDOW_HPP
#define LIBCWPP_BUFFEREDWINDOW_HPP

#include <deque>
#include <string>

#include <libcppg/thread/Mutex.h>

#include <libcwpp/core/Window.hpp>
#include <libcwpp/stream/Stream.hpp>

namespace libcwpp
{
namespace window
{

class BufferedWindow : public libcwpp::core::Window
{
  public:
    BufferedWindow(const libcwpp::core::Size& size, libcwpp::core::Canvas* canvas = NULL);
    virtual ~BufferedWindow();

    void addText(const std::string& buffer);
    libcwpp::stream::Stream& createStream(bool autoFlush = false);

    virtual void paint(void);

  private:
    bool m_lastLineClosed;

    typedef std::deque<std::string> TLines;
    TLines m_lines;

    std::deque<libcwpp::stream::Stream*> m_streams;

    cppg::thread::Mutex m_mutex;
}; /* class BufferedWindow */

} /* namespace window */
} /* namespace libcwpp */

#endif /* LIBCWPP_BUFFEREDWINDOW_HPP */
