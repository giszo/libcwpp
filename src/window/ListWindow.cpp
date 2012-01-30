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

#include <libcwpp/window/ListWindow.hpp>

using libcwpp::window::ListWindow;

ListWindow::ListWindow(const libcwpp::core::Size& size, const ListSource& source, libcwpp::core::Canvas* canvas)
    : Window(size, canvas), m_selectEnabled(false), m_selectedItem(0), m_source(source)
{
}

void ListWindow::enableSelect()
{
    m_selectEnabled = true;
}

void ListWindow::keyPressed(int key)
{
    if (!m_selectEnabled)
        return;

    switch (key)
    {
        case KEY_UP :
            if (m_selectedItem > 0)
                m_selectedItem--;
            break;

        case KEY_DOWN :
            if (m_selectedItem < m_source.getSize() - 1)
                m_selectedItem++;
            break;

        default :
            return;
    }

    invalidate();
}

void ListWindow::paint()
{
    m_canvas->clear();

    for (size_t i = 0; i < m_source.getSize(); ++i)
    {
        if (m_selectEnabled && m_selectedItem == i)
            m_canvas->print(0, i, "=> ");

        m_canvas->print(3, i, "%s", m_source.getItemAt(i).c_str());
    }
}
