#include <libcwpp/Size.hpp>

namespace libcwpp
{

Size::Size(int minWidth, int maxWidth, int minHeight, int maxHeight)
    : m_minWidth(minWidth), m_maxWidth(maxWidth), m_minHeight(minHeight), m_maxHeight(maxHeight)
{
}

int Size::minWidth(void)
{
    return m_minWidth;
}

int Size::maxWidth(void)
{
    return m_maxWidth;
}

int Size::minHeight(void)
{
    return m_minHeight;
}

int Size::maxHeight(void)
{
    return m_maxHeight;
}

bool Size::isWidthDynamic(void) const
{
    return (m_minWidth < m_maxWidth);
}

bool Size::isHeightDynamic(void) const
{
    return (m_minHeight < m_maxHeight);
}

} /* namespace libcwpp */
