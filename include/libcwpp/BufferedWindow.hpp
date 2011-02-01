#ifndef LIBCWPP_BUFFEREDWINDOW_HPP
#define LIBCWPP_BUFFEREDWINDOW_HPP

#include <deque>
#include <string>

#include <libcwpp/Window.hpp>
#include <libcwpp/stream/Stream.hpp>

namespace libcwpp
{

class BufferedWindow;

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

class BufferedWindow : public Window
{
  public:
    friend class BufferedStream;

    BufferedWindow(Size size);

    libcwpp::stream::Stream& createStream(void);

    void paint(void);

  private:
    /* This function is used by BufferedStream to flush its buffer into the window. */
    void add(const std::string& buffer);

  private:
    std::deque<std::string> m_lines;

    std::deque<libcwpp::stream::Stream*> m_streams;
}; /* class BufferedWindow */

} /* namespace libcwpp */

#endif /* LIBCWPP_BUFFEREDWINDOW_HPP */
