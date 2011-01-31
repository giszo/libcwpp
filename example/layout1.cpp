#include <limits.h>

#include <libcwpp/Window.hpp>
#include <libcwpp/RowFrame.hpp>
#include <libcwpp/ColumnFrame.hpp>
#include <libcwpp/WindowFrame.hpp>

class LineWindow : public libcwpp::Window
{
  public:
    LineWindow(void)
        : Window(libcwpp::Size(1, 1, 1, 1))
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

    libcwpp::RowFrame frame1(2);
    frame1.set(0, new libcwpp::WindowFrame(&win1));
    frame1.set(1, new libcwpp::WindowFrame(&win2));
    frame1.layout(0, 0, 80, 25);

    BigWindow win3;
    LineWindow win4;

    libcwpp::ColumnFrame frame2(2);
    frame2.set(0, new libcwpp::WindowFrame(&win3));
    frame2.set(1, new libcwpp::WindowFrame(&win4));
    frame2.layout(0, 0, 80, 25);

    return 0;
}
