#include <libcwpp/Window.hpp>

namespace libcwpp
{

Window::Window(Size size)
    : m_size(size)
{
}

const Size& Window::getSize(void)
{
    return m_size;
}

} /* namespace libcwpp */
