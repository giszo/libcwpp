#include <limits.h>

#include <algorithm>

#include <libcwpp/layout/RowFrame.hpp>

namespace libcwpp
{
namespace layout
{

RowFrame::RowFrame(void)
    : Frame()
{
}

libcwpp::core::Size RowFrame::getSize(void)
{
    int minWidth = 0;
    int maxWidth = 0;
    int minHeight = 0;
    int maxHeight = 0;

    for (std::vector<libcwpp::core::Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        libcwpp::core::Size size = (*it)->getSize();

        minWidth = std::max(minWidth, size.minWidth());
        maxWidth = std::max(maxWidth, size.maxWidth());

        minHeight += size.minHeight();

        if ((maxHeight == INT_MAX) ||
            (size.maxHeight() == INT_MAX))
        {
            maxHeight = INT_MAX;
        }
        else
        {
            maxHeight += size.maxHeight();
        }
    }

    return libcwpp::core::Size(minWidth, maxWidth, minHeight, maxHeight);
}

void RowFrame::layout(int x, int y, int width, int height)
{
    int dynamicCount = 0;
    int dynamicHeight;
    int remainingHeight = height;

    /* Do some calculation first. */
    for (std::vector<libcwpp::core::Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        libcwpp::core::Size size = (*it)->getSize();

        if (size.isHeightDynamic())
        {
            dynamicCount++;
        }
        else
        {
            remainingHeight -= size.minHeight();
        }
    }

    if (dynamicCount > 0)
    {
        dynamicHeight = remainingHeight / dynamicCount;
    }
    else
    {
        dynamicHeight = 0;
    }

    /* Do the actual layout work. */
    for (std::vector<libcwpp::core::Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        libcwpp::core::Frame* child = *it;
        libcwpp::core::Size size = child->getSize();

        if (size.isHeightDynamic())
        {
            child->layout(x, y, width, dynamicHeight);
            y += dynamicHeight;
        }
        else
        {
            int height = size.minHeight();
            child->layout(x, y, width, height);
            y += height;
        }
    }
}

} /* namespace layout */
} /* namespace libcwpp */
