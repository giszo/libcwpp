#include <unistd.h>
#include <limits.h>

#include <libcwpp/Window.hpp>
#include <libcwpp/WindowManager.hpp>

class HelloWindow : public libcwpp::Window
{
  public:
    HelloWindow(void)
        : Window(libcwpp::Size(1, INT_MAX, 1, INT_MAX))
    {}

    void paint(void)
    {
        print((width() - 11) / 2, height() / 2, "Hello World");
    }
}; /* class HelloWindow */

int main(int argc, char** argv)
{
    libcwpp::WindowManager winMgr;
    winMgr.init();

    HelloWindow window;
    winMgr.setRootFrame(&window);

    winMgr.run();
    sleep(3);
    winMgr.destroy();

    return 0;
}
