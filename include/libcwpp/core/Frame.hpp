#ifndef LIBCWPP_FRAME_HPP
#define LIBCWPP_FRAME_HPP

#include <vector>

#include <libcwpp/core/Size.hpp>

namespace libcwpp
{
namespace core
{

class WindowManager;

class Frame
{
  public:
    Frame(void);
    virtual ~Frame(void);

    virtual Size getSize(void) = 0;

    bool add(Frame* child);
    bool insert(size_t index, Frame* child);

    void setWindowManager(WindowManager* windowManager);

    virtual void paint(void);
    virtual void refresh(void);

    virtual void layout(int x, int y, int width, int height) = 0;

  protected:
    std::vector<Frame*> m_children;

    WindowManager* m_windowManager;
}; /* class Frame */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_FRAME_HPP */
