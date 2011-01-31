#ifndef LIBCWPP_COLUMNFRAME_HPP
#define LIBCWPP_COLUMNFRAME_HPP

#include <libcwpp/Frame.hpp>

namespace libcwpp
{

class ColumnFrame : public Frame
{
  public:
    ColumnFrame(int count);

    Size getSize(void);

    void layout(int x, int y, int width, int height);
}; /* class ColumnFrame */

} /* namespace libcwpp */

#endif /* LIBCWPP_COLUMNFRAME_HPP */
