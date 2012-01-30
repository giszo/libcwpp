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

#include <libcwpp/core/Frame.hpp>
#include <libcwpp/core/Canvas.hpp>

namespace libcwpp
{
namespace core
{

class Window : public Frame
{
  public:
    Window(const Size& size, Canvas* canvas);
    virtual ~Window();

    Size getSize();

    int width();
    int height();

    void layout(int x, int y, int width, int height);
    void refresh();

    void invalidate();

    virtual void keyPressed(int key);
    virtual void paint() = 0;

  protected:
    Canvas* m_canvas;

  private:
    Size m_size;

    int m_width;
    int m_height;
}; /* class Window */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_HPP */
