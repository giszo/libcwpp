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

#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#include <algorithm>

#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/core/Window.hpp>

namespace libcwpp
{
namespace core
{

WindowManager::WindowManager(void)
    : m_eventReceiver(-1), m_eventSender(-1), m_running(true)
{
}

void WindowManager::setRootFrame(const std::shared_ptr<Frame>& frame)
{
    m_rootFrame = frame;
    m_rootFrame->setWindowManager(this);
}

void WindowManager::setFocusedWindow(const std::shared_ptr<Window>& window)
{
    m_focusedWindow = window;
}

bool WindowManager::init(void)
{
    int pipes[2];

    if (pipe(pipes) != 0)
        return false;

    m_eventReceiver = pipes[0];
    m_eventSender = pipes[1];

    initscr();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    /* Push an event so the initial layout work and painting will be triggered immediately. */
    pushEvent(E_LAYOUT_CHANGED);

    return true;
}

void WindowManager::destroy(void)
{
    close(m_eventReceiver);
    close(m_eventSender);

    noraw();
    endwin();
}

int WindowManager::run(void)
{
    /* Do nothing if we have no root frame. */
    if (!m_rootFrame)
        return 0;

    /* Enter to the mainloop ... */
    while (m_running)
    {
        int ret;
        int maxFd = 0;
        fd_set readers;
        timeval timeOut = {0, 100 * 1000};

        std::set<int> r;
        std::set<int> dummy;
        buildPollTable(r, dummy, dummy);

        FD_ZERO(&readers);
        for (std::set<int>::const_iterator it = r.begin();
             it != r.end();
             ++it)
        {
            int fd = *it;
            FD_SET(fd, &readers);
            maxFd = std::max(maxFd, fd);
        }

        ret = select(maxFd + 1, &readers, NULL, NULL, &timeOut);

        if (ret > 0)
        {
            r.clear();
            dummy.clear();

            if (FD_ISSET(STDIN_FILENO, &readers))
                r.insert(STDIN_FILENO);

            if (FD_ISSET(m_eventReceiver, &readers))
                r.insert(m_eventReceiver);

            handlePollEvents(r, dummy, dummy);
        }
    }

    return 0;
}

void WindowManager::stop(void)
{
    m_running = false;
    pushEvent(E_NOP);
}

void WindowManager::buildPollTable(std::set<int>& r, std::set<int>& w, std::set<int>& e)
{
    r.insert(STDIN_FILENO);
    r.insert(m_eventReceiver);
}

void WindowManager::handlePollEvents(std::set<int>& r, std::set<int>& w, std::set<int>& e)
{
    if (r.find(STDIN_FILENO) != r.end())
        handleStdin();

    if (r.find(m_eventReceiver) != r.end())
    {
        int event = 0;

        if (read(m_eventReceiver, &event, 1) == 1)
            handleEvent(event);
    }
}

bool WindowManager::getTerminalSize(int& width, int& height)
{
    winsize size;

    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) != 0)
        return false;

    width = size.ws_col;
    height = size.ws_row;

    return true;
}

bool WindowManager::pushEvent(int event)
{
    return write(m_eventSender, &event, 1) == 1;
}

void WindowManager::handleStdin(void)
{
    int c;

    while ((c = getch()) != ERR)
    {
        if (c == 27)
            m_running = false;

        if (m_focusedWindow)
            m_focusedWindow->keyPressed(c);
    }
}

void WindowManager::handleEvent(int event)
{
    switch (event)
    {
        case E_LAYOUT_CHANGED :
        {
            int width;
            int height;

            getTerminalSize(width, height);
            m_rootFrame->layout(0, 0, width, height);

            /* Intentionally no brake here! */
        }

        case E_WINDOW_INVALIDATED :
            redrawwin(stdscr);
            m_rootFrame->paint();
            wnoutrefresh(stdscr);
            m_rootFrame->refresh();
            doupdate();
            break;

        case E_NOP :
            break;
    }
}

} /* namespace core */
} /* namespace libcwpp */
