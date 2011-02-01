#include <unistd.h>
#include <limits.h>

#include <libcwpp/core/Window.hpp>
#include <libcwpp/core/WindowManager.hpp>

class HelloWindow : public libcwpp::core::Window
{
  public:
    HelloWindow(void)
        : Window(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX))
    {}

    void paint(void)
    {
        print((width() - 11) / 2, height() / 2, "Hello World");
    }
}; /* class HelloWindow */

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    HelloWindow window;
    winMgr.setRootFrame(&window);

    winMgr.run();
    sleep(3);
    winMgr.destroy();

    return 0;
}
