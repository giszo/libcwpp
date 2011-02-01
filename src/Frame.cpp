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

Frame::~Frame(void)
{
    delete[] m_children;
}

bool Frame::set(int index, Frame* child)
{
    if ((index < 0) ||
        (index >= m_count))
    {
        return false;
    }

    m_children[index] = child;

    return true;
}

void Frame::paint(void)
{
    for (int i = 0; i < m_count; i++)
    {
        m_children[i]->paint();
    }
}

void Frame::refresh(void)
{
    for (int i = 0; i < m_count; i++)
    {
        m_children[i]->refresh();
    }
}

} /* namespace libcwpp */
