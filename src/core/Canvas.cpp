/*
 * Window manager library for console applications.
 *
 * Copyright (c) 2012 Zoltan Kovacs
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

#include <libcwpp/core/Canvas.hpp>

using libcwpp::core::Canvas;

Canvas::Canvas()
{
}

Canvas::~Canvas()
{
    if (m_window)
        delwin(m_window);
}

void Canvas::init()
{
    m_window = newwin(0, 0, 0, 0);
}

void Canvas::clear(void)
{
    werase(m_window);
}

void Canvas::print(int x, int y, const char* format, ...)
{
    va_list args;

    va_start(args, format);
    wmove(m_window, y, x);
    vw_printw(m_window, format, args);
    va_end(args);
}

void Canvas::refresh(void)
{
    wnoutrefresh(m_window);
}

void Canvas::moveTo(int x, int y, int width, int height)
{
    wresize(m_window, height, width);
    mvwin(m_window, y, x);
}
