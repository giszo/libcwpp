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

    std::shared_ptr<libcwpp::window::BufferedWindow> output1 =
        std::make_shared<libcwpp::window::BufferedWindow>(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    std::shared_ptr<libcwpp::window::BufferedWindow> output2 =
        std::make_shared<libcwpp::window::BufferedWindow>(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    std::shared_ptr<InputWindow> input = std::make_shared<InputWindow>(output1->createStream(), output2->createStream());

    std::shared_ptr<libcwpp::layout::ColumnFrame> cf = std::make_shared<libcwpp::layout::ColumnFrame>();
    cf->add(output1);
    cf->add(output2);

    std::shared_ptr<libcwpp::layout::RowFrame> rf = std::make_shared<libcwpp::layout::RowFrame>();
    rf->add(cf);
    rf->add(input);

    winMgr.setRootFrame(rf);
    winMgr.setFocusedWindow(input);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
