#include <limits.h>
#include <unistd.h>

#include <libcwpp/Window.hpp>
#include <libcwpp/RowFrame.hpp>
#include <libcwpp/ColumnFrame.hpp>
#include <libcwpp/WindowManager.hpp>

class LineWindow : public libcwpp::Window
{
  public:
    LineWindow(void)
        : Window(libcwpp::Size(1, 1, 1, 1))
    {}

    void paint(void)
    {
        print(0, 0, "This is a one-line window.");
    }
}; /* class MyWindow1 */

class BigWindow : public libcwpp::Window
{
  public:
    BigWindow(void)
        : Window(libcwpp::Size(1, INT_MAX, 1, INT_MAX))
    {}

    void paint(void)
    {
        int y = (height() - 3) / 2;

        print(10, y, "This is a");
        print(10, y + 1, "bigger window with");
        print(10, y + 2, "more than one line");
        print(width() - 3, height() - 1, ":)");
    }
};

int main(int argc, char** argv)
{
    libcwpp::WindowManager winMgr;
    winMgr.init();

    BigWindow win1;
    LineWindow win2;

    libcwpp::RowFrame frame(2);
    frame.set(0, &win1);
    frame.set(1, &win2);
    winMgr.setRootFrame(&frame);

    winMgr.run();
    sleep(3);
    winMgr.destroy();

    return 0;
}
