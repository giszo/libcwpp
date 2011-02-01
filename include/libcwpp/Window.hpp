#ifndef LIBCWPP_WINDOW_HPP
#define LIBCWPP_WINDOW_HPP

#include <ncurses.h>

#include <libcwpp/Frame.hpp>

namespace libcwpp
{

class Window : public Frame
{
  public:
    Window(Size size);
    ~Window(void);

    Size getSize(void);

    int width(void);
    int height(void);

    void layout(int x, int y, int width, int height);
    void refresh(void);

    void clear(void);
    void print(int x, int y, const char* format, ...) __attribute__(( format(printf, 4, 5) ));

    virtual void paint(void) = 0;

  private:
    Size m_size;

    int m_width;
    int m_height;

    WINDOW* m_window;
}; /* class Window */

} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOW_HPP */
