#ifndef LIBCWPP_WINDOW_INPUTWINDOW_HPP
#define LIBCWPP_WINDOW_INPUTWINDOW_HPP

#include <string>

#include <libcwpp/core/Window.hpp>

namespace libcwpp
{
namespace window
{

class InputWindow : public libcwpp::core::Window
{
  public:
    InputWindow(libcwpp::core::Size size, std::string prompt = "");

    void keyPressed(int key);
    void paint(void);

    virtual void inputReceived(const std::string& s) = 0;

  private:
    std::string m_prompt;

    size_t m_position;
    std::string m_buffer;
}; /* class InputWindow */

} /* namespace window */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_INPUTWINDOW_HPP */
