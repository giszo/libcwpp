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
        m_stream << s << "\n";
    }

  private:
    libcwpp::stream::Stream& m_stream;
}; /* class InputWindow */

int main(int argc, char** argv)
{
    libcwpp::core::WindowManager winMgr;
    winMgr.init();

    std::shared_ptr<libcwpp::window::BufferedWindow> output =
        std::make_shared<libcwpp::window::BufferedWindow>(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    std::shared_ptr<InputWindow> input = std::make_shared<InputWindow>(output->createStream(true));

    std::shared_ptr<libcwpp::layout::RowFrame> frame = std::make_shared<libcwpp::layout::RowFrame>();
    frame->add(output);
    frame->add(input);

    winMgr.setRootFrame(frame);
    winMgr.setFocusedWindow(input);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
