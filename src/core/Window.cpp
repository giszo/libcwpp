#include <libcwpp/core/Window.hpp>

namespace libcwpp
{
namespace core
{

Window::Window(Size size)
    : Frame(0), m_size(size),
      m_width(0), m_height(0)
{
    m_window = newwin(0, 0, 0, 0);
}

Window::~Window(void)
{
    delwin(m_window);
}

Size Window::getSize(void)
{
    return m_size;
}

int Window::width(void)
{
    return m_width;
}

int Window::height(void)
{
    return m_height;
}

void Window::layout(int x, int y, int width, int height)
{
    wresize(m_window, height, width);
    mvwin(m_window, y, x);

    m_width = width;
    m_height = height;
}

void Window::refresh(void)
{
    wnoutrefresh(m_window);
}

void Window::clear(void)
{
    werase(m_window);
}

void Window::print(int x, int y, const char* format, ...)
{
    va_list args;

    va_start(args, format);
    wmove(m_window, y, x);
    vw_printw(m_window, format, args);
    va_end(args);
}

} /* namespace core */
} /* namespace libcwpp */
