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

    boost::shared_ptr<libcwpp::window::BufferedWindow> output1(
        new libcwpp::window::BufferedWindow(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX)));
    boost::shared_ptr<libcwpp::window::BufferedWindow> output2(
        new libcwpp::window::BufferedWindow(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX)));
    boost::shared_ptr<InputWindow> input(new InputWindow(output1->createStream(), output2->createStream()));

    boost::shared_ptr<libcwpp::layout::ColumnFrame> cf(new libcwpp::layout::ColumnFrame());;
    cf->add(output1);
    cf->add(output2);

    boost::shared_ptr<libcwpp::layout::RowFrame> rf(new libcwpp::layout::RowFrame());
    rf->add(cf);
    rf->add(input);

    winMgr.setRootFrame(rf);
    winMgr.setFocusedWindow(input);

    winMgr.run();
    winMgr.destroy();

    return 0;
}
