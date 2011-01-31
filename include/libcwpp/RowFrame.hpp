#ifndef LIBCWPP_ROWFRAME_HPP
#define LIBCWPP_ROWFRAME_HPP

#include <libcwpp/Frame.hpp>

namespace libcwpp
{

class RowFrame : public Frame
{
  public:
    RowFrame(int count);
    virtual ~RowFrame();

    Size getSize(void);

    void layout(int x, int y, int width, int height);
}; /* class RowFrame */

} /* namespace libcwpp */

#endif /* LIBCWPP_ROWFRAME_HPP */
