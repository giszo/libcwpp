#include <assert.h>

#include <libcwpp/window/BufferedWindow.hpp>
#include <libcwpp/util/StringUtils.hpp>

namespace libcwpp
{
namespace window
{

BufferedWindow::BufferedStream::BufferedStream(BufferedWindow* window)
    : m_window(window)
{
}

libcwpp::stream::Stream& BufferedWindow::BufferedStream::operator<<(char c)
{
    m_buffer += c;
    return *this;
}

libcwpp::stream::Stream& BufferedWindow::BufferedStream::operator<<(int i)
{
    m_buffer += libcwpp::util::StringUtils::toString(i);
    return *this;
}

libcwpp::stream::Stream& BufferedWindow::BufferedStream::operator<<(const char* s)
{
    m_buffer += s;
    return *this;
}

libcwpp::stream::Stream& BufferedWindow::BufferedStream::operator<<(const std::string& s)
{
    m_buffer += s;
    return *this;
}

libcwpp::stream::Stream& BufferedWindow::BufferedStream::operator<<(const libcwpp::stream::Flush& f)
{
    m_window->add(m_buffer);
    m_buffer.clear();
    return *this;
}

BufferedWindow::BufferedWindow(libcwpp::core::Size size)
    : Window(size), m_lastLineClosed(false)
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

    clear();

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
    if (buffer.empty())
    {
        return;
    }

    std::deque<std::string> lines = libcwpp::util::StringUtils::tokenize(buffer, "\n");
    assert(!lines.empty());

    if (!m_lines.empty() && !m_lastLineClosed)
    {
        m_lines.back() += lines.front();
        lines.pop_front();
    }

    for (std::deque<std::string>::const_iterator it = lines.begin();
         it != lines.end();
         ++it)
    {
        m_lines.push_back(*it);
    }

    m_lastLineClosed = (buffer[buffer.size() - 1] == '\n');

    invalidate();
}

} /* namespace window */
} /* namespace libcwpp */
