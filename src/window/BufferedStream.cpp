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

#include <libcwpp/window/BufferedWindow.hpp>

#include "BufferedStream.hpp"
#include "../util/StringUtils.hpp"

namespace libcwpp
{
namespace window
{

BufferedStream::BufferedStream(BufferedWindow* window)
    : m_window(window)
{
}

libcwpp::stream::Stream& BufferedStream::operator<<(char c)
{
    m_buffer += c;
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(int i)
{
    m_buffer += libcwpp::util::StringUtils::toString(i);
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(const char* s)
{
    m_buffer += s;
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(const std::string& s)
{
    m_buffer += s;
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(const libcwpp::stream::Flush& f)
{
    m_window->addText(m_buffer);
    m_buffer.clear();
    return *this;
}

} /* namespace window */
} /* namespace libcwpp */
