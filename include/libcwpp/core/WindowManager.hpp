#ifndef LIBCWPP_WINDOWMANAGER_HPP
#define LIBCWPP_WINDOWMANAGER_HPP

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace core
{

class Window;

class WindowManager
{
  public:
    friend class Window;

    enum
    {
        E_LAYOUT_CHANGED = 1,
        E_WINDOW_INVALIDATED,
        E_NOP
    };

    WindowManager(void);

    void setRootFrame(Frame* frame);
    void setFocusedWindow(Window* window);

    bool init(void);
    void destroy(void);
    void stop(void);

    int run(void);

  private:
    bool getTerminalSize(int& width, int& height);

    bool pushEvent(int event);

    void handleStdin(void);
    void handleEvent(int event);

  private:
    Frame* m_rootFrame;
    Window* m_focusedWindow;

    int m_eventReceiver;
    int m_eventSender;

    volatile bool m_running;
}; /* class WindowManager */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOWMANAGER_HPP */
