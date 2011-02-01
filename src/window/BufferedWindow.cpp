#include <libcwpp/window/BufferedWindow.hpp>

namespace libcwpp
{
namespace window
{

BufferedWindow::BufferedStream::BufferedStream(BufferedWindow* window)
    : m_window(window)
{
}

libcwpp::stream::Stream& BufferedWindow::BufferedStream::operator<<(const char* s)
{
    m_buffer += s;
    return *this;
}

libcwpp::stream::Stream& BufferedWindow::BufferedStream::operator<<(const libcwpp::stream::Flush& f)
{
    m_window->add(m_buffer);
    m_buffer.clear();
    // todo: repaint the window
    return *this;
}

BufferedWindow::BufferedWindow(libcwpp::core::Size size)
    : Window(size)
{
}

libcwpp::stream::Stream& BufferedWindow::createStream(void)
{
    libcwpp::stream::Stream* stream = new BufferedStream(this);
    m_streams.push_back(stream);
    return *stream;
}

void BufferedWindow::paint(void)
{
    int y = 0;

    for (std::deque<std::string>::const_iterator it = m_lines.begin();
         it != m_lines.end();
         ++it)
    {
        const std::string& line = *it;
        print(0, y++, "%s", line.c_str());
    }
}

void BufferedWindow::add(const std::string& buffer)
{
    m_lines.push_back(buffer);
}

} /* namespace window */
} /* namespace libcwpp */
