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

#ifndef LIBCWPP_WINDOWMANAGER_HPP
#define LIBCWPP_WINDOWMANAGER_HPP

#include <set>

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace core
{

class Window;

class WindowManager
{
  public:
    friend class Window;

    enum
    {
        E_LAYOUT_CHANGED = 1,
        E_WINDOW_INVALIDATED,
        E_NOP
    };

    WindowManager(void);

    void setRootFrame(Frame* frame);
    void setFocusedWindow(Window* window);

    bool init(void);
    void destroy(void);

    int run(void);
    void stop(void);

    void buildPollTable(std::set<int>& r, std::set<int>& w, std::set<int>& e);
    void handlePollEvents(std::set<int>& r, std::set<int>& w, std::set<int>& e);

  private:
    bool getTerminalSize(int& width, int& height);

    bool pushEvent(int event);

    void handleStdin(void);
    void handleEvent(int event);

  private:
    Frame* m_rootFrame;
    Window* m_focusedWindow;

    int m_eventReceiver;
    int m_eventSender;

    volatile bool m_running;
}; /* class WindowManager */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOWMANAGER_HPP */
