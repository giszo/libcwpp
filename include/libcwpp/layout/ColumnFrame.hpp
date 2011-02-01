#ifndef LIBCWPP_COLUMNFRAME_HPP
#define LIBCWPP_COLUMNFRAME_HPP

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace layout
{

class ColumnFrame : public libcwpp::core::Frame
{
  public:
    ColumnFrame(int count);
    virtual ~ColumnFrame(void);

    libcwpp::core::Size getSize(void);

    void layout(int x, int y, int width, int height);
}; /* class ColumnFrame */

} /* namespace layout */
} /* namespace libcwpp */

#endif /* LIBCWPP_COLUMNFRAME_HPP */
