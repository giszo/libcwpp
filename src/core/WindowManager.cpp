#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#include <iostream>
#include <algorithm>

#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/core/Window.hpp>

namespace libcwpp
{
namespace core
{

WindowManager::WindowManager(void)
    : m_rootFrame(NULL), m_focusedWindow(NULL),
      m_eventReceiver(-1), m_eventSender(-1),
      m_running(true)
{
}

void WindowManager::setRootFrame(Frame* frame)
{
    m_rootFrame = frame;
    m_rootFrame->setWindowManager(this);
}

void WindowManager::setFocusedWindow(Window* window)
{
    m_focusedWindow = window;
}

bool WindowManager::init(void)
{
    int pipes[2];

    if (pipe(pipes) != 0)
    {
        return false;
    }

    m_eventReceiver = pipes[0];
    m_eventSender = pipes[1];

    initscr();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    return true;
}

void WindowManager::destroy(void)
{
    close(m_eventReceiver);
    close(m_eventSender);

    noraw();
    endwin();
}

void WindowManager::stop(void)
{
    m_running = false;
    pushEvent(E_NOP);
}

int WindowManager::run(void)
{
    /* Do nothing if we have no root frame. */
    if (m_rootFrame == NULL)
    {
        return 0;
    }

    /* Push an event so the initial layout work and painting will be triggered immediately. */
    pushEvent(E_LAYOUT_CHANGED);

    /* Enter to the mainloop ... */
    while (m_running)
    {
        int ret;
        fd_set r;
        timeval timeOut = {0, 100 * 1000};

        FD_ZERO(&r);
        FD_SET(STDIN_FILENO, &r);
        FD_SET(m_eventReceiver, &r);

        ret = select(std::max(STDIN_FILENO, m_eventReceiver) + 1, &r, NULL, NULL, &timeOut);

        if (ret > 0)
        {
            if (FD_ISSET(STDIN_FILENO, &r))
            {
                handleStdin();
            }

            if (FD_ISSET(m_eventReceiver, &r))
            {
                int event;

                if (read(m_eventReceiver, &event, 1) == 1)
                {
                    handleEvent(event);
                }
            }
        }
    }

    return 0;
}

bool WindowManager::getTerminalSize(int& width, int& height)
{
    winsize size;

    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) != 0)
    {
        return false;
    }

    width = size.ws_col;
    height = size.ws_row;

    return true;
}

bool WindowManager::pushEvent(int event)
{
    int ret;
    ret = write(m_eventSender, &event, 1);
    return (ret == 1);
}

void WindowManager::handleStdin(void)
{
    int c;

    while ((c = getch()) != ERR)
    {
        if (c == 27)
        {
            m_running = false;
        }

        if (m_focusedWindow != NULL)
        {
            m_focusedWindow->keyPressed(c);
        }
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
