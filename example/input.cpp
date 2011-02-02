#include <limits.h>

#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/window/BufferedWindow.hpp>
#include <libcwpp/window/InputWindow.hpp>
#include <libcwpp/layout/RowFrame.hpp>

class InputWindow : public libcwpp::window::InputWindow
{
  public:
    InputWindow(libcwpp::stream::Stream& stream)
        : libcwpp::window::InputWindow(libcwpp::core::Size(1, INT_MAX, 1, 1)), m_stream(stream)
    {}

    void inputReceived(const std::string& s)
    {
        m_stream << s << "\n" << libcwpp::stream::Flush();
    }

  private:
    libcwpp::stream::Stream& m_stream;
}; /* class InputWindow */

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    libcwpp::window::BufferedWindow output(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    InputWindow input(output.createStream());

    libcwpp::layout::RowFrame frame(2);
    frame.set(0, &output);
    frame.set(1, &input);

    winMgr.setRootFrame(&frame);
    winMgr.setFocusedWindow(&input);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
