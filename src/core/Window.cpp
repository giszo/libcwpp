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

using libcwpp::core::Window;

Window::Window(const libcwpp::core::Size& size, libcwpp::core::Canvas* canvas)
    : Frame(), m_size(size),
      m_width(0), m_height(0)
{
    if (canvas)
        m_canvas = canvas;
    else
    {
        m_canvas = new Canvas();
        m_canvas->init();
    }
}

Window::~Window(void)
{
    delete m_canvas;
}

libcwpp::core::Size Window::getSize(void)
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
    m_canvas->moveTo(x, y, width, height);

    m_width = width;
    m_height = height;
}

void Window::refresh()
{
    m_canvas->refresh();
}

void Window::invalidate(void)
{
    if (!m_windowManager)
        return;

    m_windowManager->pushEvent(WindowManager::E_WINDOW_INVALIDATED);
}

void Window::keyPressed(int key)
{
    /* do nothing here ... */
}
