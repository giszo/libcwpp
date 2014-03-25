#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/window/ListWindow.hpp>

class MySource : public libcwpp::window::ListSource
{
  public:
    size_t getSize() const
    {
        return 3;
    }

    std::string getItemAt(size_t i) const
    {
        switch (i)
        {
            case 0 : return "Hello";
            case 1 : return "from";
            case 2 : return "ListView :)";
            default : return "";
        }
    }
};

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    MySource source;
    std::shared_ptr<libcwpp::window::ListWindow> win =
        std::make_shared<libcwpp::window::ListWindow>(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX), source);
    win->enableSelect();

    winMgr.setRootFrame(win);
    winMgr.setFocusedWindow(win);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
