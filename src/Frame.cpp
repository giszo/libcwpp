#include <stddef.h>

#include <libcwpp/Frame.hpp>

namespace libcwpp
{

Frame::Frame(int count)
    : m_count(count), m_children(NULL)
{
    if (m_count > 0)
    {
        m_children = new Frame*[m_count];

        for (int i = 0; i < m_count; i++)
        {
            m_children[i] = NULL;
        }
    }
}

void Frame::set(int index, Frame* child)
{
    if ((index < 0) ||
        (index >= m_count))
    {
        return;
    }

    m_children[index] = child;
}

} /* namespace libcwpp */
