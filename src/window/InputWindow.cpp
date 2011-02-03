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

#include <iostream>

#include <libcwpp/window/InputWindow.hpp>

namespace libcwpp
{
namespace window
{

InputWindow::InputWindow(libcwpp::core::Size size, std::string prompt)
    : Window(size), m_prompt(prompt), m_position(0)
{
}

void InputWindow::keyPressed(int key)
{
    switch (key)
    {
        case '\n' :
        case KEY_ENTER :
            inputReceived(m_buffer);
            m_position = 0;
            m_buffer.clear();
            break;

        case KEY_LEFT :
            if (m_position > 0)
            {
                m_position--;
            }
            break;

        case KEY_RIGHT :
            if (m_position < m_buffer.size())
            {
                m_position++;
            }
            break;

        case KEY_HOME :
            m_position = 0;
            break;

        case KEY_END :
            m_position = m_buffer.size();
            break;

        case 0x7f :
        case KEY_BACKSPACE :
            if (m_position > 0)
            {
                m_position--;
                m_buffer.erase(m_position, 1);
            }
            break;

        case KEY_DC :
            if (m_position < m_buffer.size())
            {
                m_buffer.erase(m_position, 1);
            }
            break;

        case KEY_UP :
        case KEY_DOWN :
            /* At the moment this is a one-line input window so skip these keys. */
            return;

        default :
            m_buffer.insert(m_position++, 1, (char)key);
            break;
    }

    invalidate();
}

void InputWindow::paint(void)
{
    clear();

    if (!m_prompt.empty())
    {
        print(0, 0, "%s", m_prompt.c_str());
    }

    print(m_prompt.size(), 0, "%s", m_buffer.c_str());
}

} /* namespace window */
} /* namespace libcwpp */
