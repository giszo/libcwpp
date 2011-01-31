#include <libcwpp/RowFrame.hpp>

namespace libcwpp
{

RowFrame::RowFrame(int count)
    : Frame(count)
{
}

Size RowFrame::getSize(void)
{
    // todo
    return Size(0, 0, 0, 0);
}

void RowFrame::layout(int x, int y, int width, int height)
{
    int dynamicCount = 0;
    int remainingHeight = height;

    /* Do some calculation first. */
    for (int i = 0; i < m_count; i++)
    {
        Frame* child = m_children[i];
        Size size = child->getSize();

        if (size.isHeightDynamic())
        {
            dynamicCount++;
        }
        else
        {
            remainingHeight -= size.minHeight();
        }
    }

    int dynamicHeight = remainingHeight / dynamicCount;

    /* Do the actual layout work. */
    for (int i = 0; i < m_count; i++)
    {
        Frame* child = m_children[i];
        Size size = child->getSize();

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

} /* namespace libcwpp */
