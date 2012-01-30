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

#ifndef LIBCWPP_CANVAS_HPP
#define LIBCWPP_CANVAS_HPP

#include <ncurses.h>

namespace libcwpp
{
namespace core
{

class Canvas
{
  public:
    Canvas();
    ~Canvas();

    virtual void clear();
    virtual void print(int x, int y, const char* format, ...) __attribute__((format(printf, 4, 5)));

    void refresh();

    void moveTo(int x, int y, int width, int height);

  private:
    WINDOW* m_window;
};

}
}

#endif
