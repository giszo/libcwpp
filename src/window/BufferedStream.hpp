#ifndef LIBCWPP_WINDOW_BUFFEREDSTREAM_HPP
#define LIBCWPP_WINDOW_BUFFEREDSTREAM_HPP

#include <libcwpp/stream/Stream.hpp>

namespace libcwpp
{
namespace window
{

class BufferedWindow;

class BufferedStream : public libcwpp::stream::Stream
{
  public:
    BufferedStream(BufferedWindow* window);

    libcwpp::stream::Stream& operator<<(char c);
    libcwpp::stream::Stream& operator<<(int i);
    libcwpp::stream::Stream& operator<<(const char* s);
    libcwpp::stream::Stream& operator<<(const std::string& s);

    libcwpp::stream::Stream& operator<<(const libcwpp::stream::Flush& f);

  private:
    std::string m_buffer;

    BufferedWindow* m_window;
}; /* class BufferedStream */

} /* namespace window */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_BUFFEREDSTREAM_HPP */
