#include <unistd.h>
#include <limits.h>

#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/window/BufferedWindow.hpp>

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    libcwpp::window::BufferedWindow win(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    winMgr.setRootFrame(&win);

    libcwpp::stream::Stream& s = win.createStream();

    s << "Hello";
    s << " ";
    s << "World!";
    s << "\n";
    s << libcwpp::stream::Flush();

    s << "This is the second line!\n\n";
    s << libcwpp::stream::Flush();

    s << "This will be\nsplitted into two lines";
    s << libcwpp::stream::Flush();

    s << "\n\n";
    s << 'c';
    s << "=";
    s << 42;
    s << "\n";
    s << libcwpp::stream::Flush();

    winMgr.run();
    sleep(3);
    winMgr.destroy();

    return 0;
}
