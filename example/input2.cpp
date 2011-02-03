#include <limits.h>

#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/window/BufferedWindow.hpp>
#include <libcwpp/window/InputWindow.hpp>
#include <libcwpp/layout/RowFrame.hpp>
#include <libcwpp/layout/ColumnFrame.hpp>

class InputWindow : public libcwpp::window::InputWindow
{
  public:
    InputWindow(libcwpp::stream::Stream& stream1, libcwpp::stream::Stream& stream2)
        : libcwpp::window::InputWindow(libcwpp::core::Size(1, INT_MAX, 1, 1)),
          m_stream1(stream1), m_stream2(stream2)
    {}

    void inputReceived(const std::string& s)
    {
        m_stream1 << s << "\n" << libcwpp::stream::Flush();
        m_stream2 << s << "\n" << libcwpp::stream::Flush();
    }

  private:
    libcwpp::stream::Stream& m_stream1;
    libcwpp::stream::Stream& m_stream2;
}; /* class InputWindow */

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    libcwpp::window::BufferedWindow output1(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    libcwpp::window::BufferedWindow output2(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    InputWindow input(output1.createStream(), output2.createStream());

    libcwpp::layout::ColumnFrame cf(2);
    cf.set(0, &output1);
    cf.set(1, &output2);

    libcwpp::layout::RowFrame frame(2);
    frame.set(0, &cf);
    frame.set(1, &input);

    winMgr.setRootFrame(&frame);
    winMgr.setFocusedWindow(&input);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
