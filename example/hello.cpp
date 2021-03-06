#include <libcwpp/core/Window.hpp>
#include <libcwpp/core/WindowManager.hpp>

class HelloWindow : public libcwpp::core::Window
{
  public:
    HelloWindow(void)
        : Window(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX), NULL)
    {}

    void paint(void)
    {
        m_canvas->print((width() - 11) / 2, height() / 2, "Hello World");
    }
}; /* class HelloWindow */

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    std::shared_ptr<HelloWindow> window = std::make_shared<HelloWindow>();
    winMgr.setRootFrame(window);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
