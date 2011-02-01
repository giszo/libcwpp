#include <libcwpp/window/InputWindow.hpp>

namespace libcwpp
{
namespace window
{

InputWindow::InputWindow(libcwpp::core::Size size, std::string prompt)
    : Window(size), m_prompt(prompt), m_position(0)
{
}

void InputWindow::keyPressed(int key)
{
    switch (key)
    {
        case '\n' :
        case KEY_ENTER :
            m_position = 0;
            m_buffer.clear();
            break;

        case KEY_LEFT :
            if (m_position > 0)
            {
                m_position--;
            }
            break;

        case KEY_RIGHT :
            if (m_position < m_buffer.size())
            {
                m_position++;
            }
            break;

        case KEY_HOME :
            m_position = 0;
            break;

        case KEY_END :
            m_position = m_buffer.size();
            break;

        case KEY_BACKSPACE :
            if (m_position > 0)
            {
                m_position--;
                m_buffer.erase(m_position, 1);
            }
            break;

        case KEY_DC :
            if (m_position < m_buffer.size())
            {
                m_buffer.erase(m_position, 1);
            }
            break;

        case KEY_UP :
        case KEY_DOWN :
            /* At the moment this is a one-line input window so skip these keys. */
            return;

        default :
            m_buffer.insert(m_position++, 1, (char)key);
            break;
    }

    invalidate();
}

void InputWindow::paint(void)
{
    clear();

    if (!m_prompt.empty())
    {
        print(0, 0, "%s", m_prompt.c_str());
    }

    print(m_prompt.size(), 0, "%s", m_buffer.c_str());
}

} /* namespace window */
} /* namespace libcwpp */
