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

#ifndef LIBCWPP_WINDOW_INPUTWINDOW_HPP
#define LIBCWPP_WINDOW_INPUTWINDOW_HPP

#include <string>

#include <libcwpp/core/Window.hpp>

namespace libcwpp
{
namespace window
{

class InputWindow : public libcwpp::core::Window
{
  public:
    InputWindow(libcwpp::core::Size size, std::string prompt = "");

    void keyPressed(int key);
    void paint(void);

    virtual void inputReceived(const std::string& s) = 0;

  private:
    std::string m_prompt;

    size_t m_position;
    std::string m_buffer;
}; /* class InputWindow */

} /* namespace window */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_INPUTWINDOW_HPP */
