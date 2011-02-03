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

#include <libcwpp/core/Window.hpp>
#include <libcwpp/core/WindowManager.hpp>

namespace libcwpp
{
namespace core
{

Window::Window(Size size)
    : Frame(), m_size(size),
      m_width(0), m_height(0)
{
    m_window = newwin(0, 0, 0, 0);
}

Window::~Window(void)
{
    delwin(m_window);
}

Size Window::getSize(void)
{
    return m_size;
}

int Window::width(void)
{
    return m_width;
}

int Window::height(void)
{
    return m_height;
}

void Window::layout(int x, int y, int width, int height)
{
    wresize(m_window, height, width);
    mvwin(m_window, y, x);

    m_width = width;
    m_height = height;
}

void Window::refresh(void)
{
    wnoutrefresh(m_window);
}

void Window::clear(void)
{
    werase(m_window);
}

void Window::print(int x, int y, const char* format, ...)
{
    va_list args;

    va_start(args, format);
    wmove(m_window, y, x);
    vw_printw(m_window, format, args);
    va_end(args);
}

void Window::invalidate(void)
{
    if (m_windowManager == NULL)
    {
        return;
    }

    m_windowManager->pushEvent(WindowManager::E_WINDOW_INVALIDATED);
}

void Window::keyPressed(int key)
{
    /* do nothing here ... */
}

} /* namespace core */
} /* namespace libcwpp */
