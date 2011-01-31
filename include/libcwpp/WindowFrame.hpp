#ifndef LIBCWPP_WINDOWFRAME_HPP
#define LIBCWPP_WINDOWFRAME_HPP

#include <libcwpp/Frame.hpp>
#include <libcwpp/Window.hpp>

namespace libcwpp
{

class WindowFrame : public Frame
{
  public:
    WindowFrame(Window* window);

    Size getSize(void);

    void layout(int x, int y, int width, int height);

  private:
    Window* m_window;
}; /* class WindowFrame */

} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOWFRAME_HPP */
