#ifndef LIBCWPP_WINDOW_HPP
#define LIBCWPP_WINDOW_HPP

#include <libcwpp/Size.hpp>

namespace libcwpp
{

class Window
{
  public:
    Window(Size size);

    const Size& getSize(void);

    virtual void paint(void) = 0;

  private:
    Size m_size;
}; /* class Window */

} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_HPP */
