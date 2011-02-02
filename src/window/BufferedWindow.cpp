#include <assert.h>

#include <libcwpp/window/BufferedWindow.hpp>

#include "BufferedStream.hpp"
#include "../util/StringUtils.hpp"

namespace libcwpp
{
namespace window
{

BufferedWindow::BufferedWindow(libcwpp::core::Size size)
    : Window(size), m_lastLineClosed(false)
{
}

void BufferedWindow::addText(const std::string& buffer)
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

} /* namespace window */
} /* namespace libcwpp */
