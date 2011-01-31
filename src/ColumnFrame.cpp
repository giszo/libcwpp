#include <libcwpp/ColumnFrame.hpp>

namespace libcwpp
{

ColumnFrame::ColumnFrame(int count)
    : Frame(count)
{
}

Size ColumnFrame::getSize(void)
{
    // todo
    return Size(0, 0, 0, 0);
}

void ColumnFrame::layout(int x, int y, int width, int height)
{
    int dynamicCount = 0;
    int remainingWidth = width;

    /* Do some calculation first. */
    for (int i = 0; i < m_count; i++)
    {
        Frame* child = m_children[i];
        Size size = child->getSize();

        if (size.isWidthDynamic())
        {
            dynamicCount++;
        }
        else
        {
            remainingWidth -= size.minWidth();
        }
    }

    int dynamicWidth = remainingWidth / dynamicCount;

    /* Do the actual layout work. */
    for (int i = 0; i < m_count; i++)
    {
        Frame* child = m_children[i];
        Size size = child->getSize();

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

} /* namespace libcwpp */
