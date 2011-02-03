#include <limits.h>

#include <algorithm>

#include <libcwpp/layout/ColumnFrame.hpp>

namespace libcwpp
{
namespace layout
{

ColumnFrame::ColumnFrame(void)
    : Frame()
{
}

libcwpp::core::Size ColumnFrame::getSize(void)
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

        minWidth += size.minWidth();

        if ((maxWidth == INT_MAX) ||
            (size.maxWidth() == INT_MAX))
        {
            maxWidth = INT_MAX;
        }
        else
        {
            maxWidth += size.maxWidth();
        }

        minHeight = std::max(minHeight, size.minHeight());
        maxHeight = std::max(maxHeight, size.maxHeight());
    }

    return libcwpp::core::Size(minWidth, maxWidth, minHeight, maxHeight);
}

void ColumnFrame::layout(int x, int y, int width, int height)
{
    int dynamicCount = 0;
    int dynamicWidth;
    int remainingWidth = width;

    /* Do some calculation first. */
    for (std::vector<libcwpp::core::Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        libcwpp::core::Size size = (*it)->getSize();

        if (size.isWidthDynamic())
        {
            dynamicCount++;
        }
        else
        {
            remainingWidth -= size.minWidth();
        }
    }

    if (dynamicCount > 0)
    {
        dynamicWidth = remainingWidth / dynamicCount;
    }
    else
    {
        dynamicWidth = 0;
    }

    /* Do the actual layout work. */
    for (std::vector<libcwpp::core::Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        libcwpp::core::Frame* child = *it;
        libcwpp::core::Size size = child->getSize();

        if (size.isWidthDynamic())
        {
            child->layout(x, y, dynamicWidth, height);
            x += dynamicWidth;
        }
        else
        {
            int width = size.minWidth();
            child->layout(x, y, width, height);
            x += width;
        }
    }
}

} /* namespace layout */
} /* namespace libcwpp */
