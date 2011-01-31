#include <iostream>

#include <libcwpp/WindowFrame.hpp>

namespace libcwpp
{

WindowFrame::WindowFrame(Window* window)
    : Frame(0), m_window(window)
{
}

WindowFrame::~WindowFrame(void)
{
}

Size WindowFrame::getSize(void)
{
    return m_window->getSize();
}

void WindowFrame::layout(int x, int y, int width, int height)
{
    std::cerr << "WindowFrame::layout: x=" << x << " y=" << y << " w=" << width << " h=" << height << std::endl;
}

} /* namespace libcwpp */
