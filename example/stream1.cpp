#include <unistd.h>
#include <limits.h>

#include <libcwpp/WindowManager.hpp>
#include <libcwpp/BufferedWindow.hpp>

int main(int argc, char** argv)
{
    libcwpp::WindowManager winMgr;
    winMgr.init();

    libcwpp::BufferedWindow win(libcwpp::Size(1, INT_MAX, 1, INT_MAX));
    winMgr.setRootFrame(&win);

    libcwpp::stream::Stream& s = win.createStream();

    s << "Hello";
    s << " ";
    s << "World!";
    s << libcwpp::stream::Flush();

    s << "This is the second line!" << libcwpp::stream::Flush();

    winMgr.run();
    sleep(3);
    winMgr.destroy();

    return 0;
}
