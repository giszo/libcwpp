#ifndef LIBCWPP_ROWFRAME_HPP
#define LIBCWPP_ROWFRAME_HPP

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace layout
{

class RowFrame : public libcwpp::core::Frame
{
  public:
    RowFrame(void);

    libcwpp::core::Size getSize(void);

    void layout(int x, int y, int width, int height);
}; /* class RowFrame */

} /* namespace layout */
} /* namespace libcwpp */

#endif /* LIBCWPP_ROWFRAME_HPP */
