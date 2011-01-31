#include <limits.h>

#include <libcwpp/Window.hpp>
#include <libcwpp/RowFrame.hpp>
#include <libcwpp/WindowFrame.hpp>

class LineWindow : public libcwpp::Window
{
  public:
    LineWindow(void)
        : Window(libcwpp::Size(1, INT_MAX, 1, 1))
    {}

    void paint(void) {}
}; /* class MyWindow1 */

class BigWindow : public libcwpp::Window
{
  public:
    BigWindow(void)
        : Window(libcwpp::Size(1, INT_MAX, 1, INT_MAX))
    {}

    void paint(void) {}
};

int main(int argc, char** argv)
{
    BigWindow win1;
    LineWindow win2;

    libcwpp::RowFrame frame(2);
    frame.set(0, new libcwpp::WindowFrame(&win1));
    frame.set(1, new libcwpp::WindowFrame(&win2));
    frame.layout(0, 0, 80, 25);

    return 0;
}
