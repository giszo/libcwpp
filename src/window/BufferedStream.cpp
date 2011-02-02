#include <libcwpp/window/BufferedWindow.hpp>

#include "BufferedStream.hpp"
#include "../util/StringUtils.hpp"

namespace libcwpp
{
namespace window
{

BufferedStream::BufferedStream(BufferedWindow* window)
    : m_window(window)
{
}

libcwpp::stream::Stream& BufferedStream::operator<<(char c)
{
    m_buffer += c;
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(int i)
{
    m_buffer += libcwpp::util::StringUtils::toString(i);
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(const char* s)
{
    m_buffer += s;
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(const std::string& s)
{
    m_buffer += s;
    return *this;
}

libcwpp::stream::Stream& BufferedStream::operator<<(const libcwpp::stream::Flush& f)
{
    m_window->addText(m_buffer);
    m_buffer.clear();
    return *this;
}

} /* namespace window */
} /* namespace libcwpp */
