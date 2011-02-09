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

#ifndef LIBCWPP_WINDOW_BUFFEREDSTREAM_HPP
#define LIBCWPP_WINDOW_BUFFEREDSTREAM_HPP

#include <libcwpp/stream/Stream.hpp>

namespace libcwpp
{
namespace window
{

class BufferedWindow;

class BufferedStream : public libcwpp::stream::Stream
{
  public:
    BufferedStream(BufferedWindow* window, bool autoFlush);

    libcwpp::stream::Stream& operator<<(char c);
    libcwpp::stream::Stream& operator<<(int i);
    libcwpp::stream::Stream& operator<<(const char* s);
    libcwpp::stream::Stream& operator<<(const std::string& s);

    libcwpp::stream::Stream& operator<<(const libcwpp::stream::Flush& f);

  private:
    void flushIfNeeded(void);

  private:
    std::string m_buffer;

    BufferedWindow* m_window;
    bool m_autoFlush;
}; /* class BufferedStream */

} /* namespace window */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_BUFFEREDSTREAM_HPP */
