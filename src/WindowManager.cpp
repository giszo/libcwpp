#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>

#include <libcwpp/WindowManager.hpp>

namespace libcwpp
{

WindowManager::WindowManager(void)
    : m_rootFrame(NULL)
{
}

void WindowManager::setRootFrame(Frame* frame)
{
    m_rootFrame = frame;
}

bool WindowManager::init(void)
{
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
    noraw();
    endwin();
}

int WindowManager::run(void)
{
    int width;
    int height;

    /* Do nothing if we have no root frame. */
    if (m_rootFrame == NULL)
    {
        return 0;
    }

    /* Get the size of the terminal and create the initial layout. */
    getTerminalSize(width, height);
    m_rootFrame->layout(0, 0, width, height);

    m_rootFrame->paint();

    /* Refresh the screen and all the windows. */
    wnoutrefresh(stdscr);
    m_rootFrame->refresh();

    doupdate();

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

} /* namespace libcwpp */
