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

    void addText(const std::string& buffer);
    libcwpp::stream::Stream& createStream(void);

    void paint(void);

  private:
    bool m_lastLineClosed;
    std::deque<std::string> m_lines;

    std::deque<libcwpp::stream::Stream*> m_streams;
}; /* class BufferedWindow */

} /* namespace window */
} /* namespace libcwpp */

#endif /* LIBCWPP_BUFFEREDWINDOW_HPP */
