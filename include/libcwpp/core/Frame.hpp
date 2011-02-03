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

#ifndef LIBCWPP_FRAME_HPP
#define LIBCWPP_FRAME_HPP

#include <vector>

#include <libcwpp/core/Size.hpp>

namespace libcwpp
{
namespace core
{

class WindowManager;

class Frame
{
  public:
    Frame(void);
    virtual ~Frame(void);

    virtual Size getSize(void) = 0;

    bool add(Frame* child);
    bool insert(size_t index, Frame* child);

    void setWindowManager(WindowManager* windowManager);

    virtual void paint(void);
    virtual void refresh(void);

    virtual void layout(int x, int y, int width, int height) = 0;

  protected:
    std::vector<Frame*> m_children;

    WindowManager* m_windowManager;
}; /* class Frame */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_FRAME_HPP */
