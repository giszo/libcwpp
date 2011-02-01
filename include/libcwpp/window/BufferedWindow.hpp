#ifndef LIBCWPP_BUFFEREDWINDOW_HPP
#define LIBCWPP_BUFFEREDWINDOW_HPP

#include <deque>
#include <string>

#include <libcwpp/core/Window.hpp>
#include <libcwpp/stream/Stream.hpp>

namespace libcwpp
{
namespace window
{

class BufferedWindow : public libcwpp::core::Window
{
  public:
    BufferedWindow(libcwpp::core::Size size);

    libcwpp::stream::Stream& createStream(void);

    void paint(void);

  private:
    class BufferedStream : public libcwpp::stream::Stream
    {
      public:
        BufferedStream(BufferedWindow* window);

        libcwpp::stream::Stream& operator<<(const char* s);

        libcwpp::stream::Stream& operator<<(const libcwpp::stream::Flush& f);

      private:
        std::string m_buffer;

        BufferedWindow* m_window;
    }; /* class BufferedStream */

    /* This function is used by BufferedStream to flush its buffer into the window. */
    void add(const std::string& buffer);

  private:
    std::deque<std::string> m_lines;

    std::deque<libcwpp::stream::Stream*> m_streams;
}; /* class BufferedWindow */

} /* namespace window */
} /* namespace libcwpp */

#endif /* LIBCWPP_BUFFEREDWINDOW_HPP */
