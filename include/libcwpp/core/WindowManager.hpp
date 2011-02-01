#ifndef LIBCWPP_WINDOWMANAGER_HPP
#define LIBCWPP_WINDOWMANAGER_HPP

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace core
{

class WindowManager
{
  public:
    WindowManager(void);

    void setRootFrame(Frame* frame);

    bool init(void);
    void destroy(void);

    int run(void);

  private:
    bool getTerminalSize(int& width, int& height);

  private:
    Frame* m_rootFrame;
}; /* class WindowManager */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_WINDOWMANAGER_HPP */
