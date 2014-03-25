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

#ifndef LIBCWPP_LISTWINDOW_HPP
#define LIBCWPP_LISTWINDOW_HPP

#include <string>

#include <libcwpp/core/Window.hpp>

namespace libcwpp
{
namespace window
{

class ListSource
{
  public:
    virtual ~ListSource()
    {}

    virtual size_t getSize() const = 0;
    virtual std::string getItemAt(size_t i) const = 0;
};

class ListWindow : public core::Window
{
  public:
    ListWindow(const libcwpp::core::Size& size, const ListSource& source, libcwpp::core::Canvas* canvas = NULL);

    void enableSelect();

    void keyPressed(int key) override;
    void paint() override;

  private:
    bool m_selectEnabled;
    size_t m_selectedItem;

    const ListSource& m_source;
};

}
}

#endif
