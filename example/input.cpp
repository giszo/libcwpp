#include <limits.h>

#include <libcwpp/core/WindowManager.hpp>
#include <libcwpp/window/BufferedWindow.hpp>
#include <libcwpp/layout/RowFrame.hpp>

class InputWindow : public libcwpp::core::Window
{
  public:
    InputWindow(libcwpp::stream::Stream& stream)
        : Window(libcwpp::core::Size(1, INT_MAX, 1, 1)), m_stream(stream)
    {}

    void paint(void)
    {
        clear();
        print(0, 0, "%s", m_buffer.c_str());
    }

    void keyPressed(int key)
    {
        switch (key)
        {
            case '\n' :
            case KEY_ENTER :
                m_stream << m_buffer << "\n" << libcwpp::stream::Flush();
                m_buffer.clear();
                break;

            default :
                m_buffer += (char)key;
                break;
        }

        invalidate();
    }

  private:
    std::string m_buffer;
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
