#include <libcwpp/core/Window.hpp>
#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/layout/RowFrame.hpp>

class LineWindow : public libcwpp::core::Window
{
  public:
    LineWindow(void)
        : Window(libcwpp::core::Size(1, 1, 1, 1), NULL)
    {}

    void paint(void)
    {
        m_canvas->print(0, 0, "This is a one-line window.");
    }
}; /* class MyWindow1 */

class BigWindow : public libcwpp::core::Window
{
  public:
    BigWindow(void)
        : Window(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX), NULL)
    {}

    void paint(void)
    {
        int y = (height() - 3) / 2;

        m_canvas->print(10, y, "This is a");
        m_canvas->print(10, y + 1, "bigger window with");
        m_canvas->print(10, y + 2, "more than one line");
        m_canvas->print(width() - 3, height() - 1, ":)");
    }
};

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    boost::shared_ptr<BigWindow> win1(new BigWindow());
    boost::shared_ptr<LineWindow> win2(new LineWindow());

    boost::shared_ptr<libcwpp::layout::RowFrame> frame(new libcwpp::layout::RowFrame());
    frame->add(win1);
    frame->add(win2);
    winMgr.setRootFrame(frame);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
