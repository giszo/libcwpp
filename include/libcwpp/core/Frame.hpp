#ifndef LIBCWPP_FRAME_HPP
#define LIBCWPP_FRAME_HPP

#include <libcwpp/core/Size.hpp>

namespace libcwpp
{
namespace core
{

class Frame
{
  public:
    Frame(int count);
    virtual ~Frame(void);

    virtual Size getSize(void) = 0;

    bool set(int index, Frame* child);

    virtual void paint(void);
    virtual void refresh(void);

    virtual void layout(int x, int y, int width, int height) = 0;

  protected:
    int m_count;
    Frame** m_children;
}; /* class Frame */

} /* namespace core */
} /* namespace libcwpp */

#endif /* LIBCWPP_FRAME_HPP */
