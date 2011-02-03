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

#ifndef LIBCWPP_WINDOW_HPP
#define LIBCWPP_WINDOW_HPP

#include <ncurses.h>

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace core
{

class Window : public Frame
{
  public:
    Window(Size size);
    ~Window(void);

    Size getSize(void);

    int width(void);
    int height(void);

    void layout(int x, int y, int width, int height);
    void refresh(void);

    void clear(void);
    void print(int x, int y, const char* format, ...) __attribute__(( format(printf, 4, 5) ));

    void invalidate(void);

    virtual void keyPressed(int key);
    virtual void paint(void) = 0;

  private:
    Size m_size;

    int m_width;
    int m_height;

    WINDOW* m_window;
}; /* class Window */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_HPP */
