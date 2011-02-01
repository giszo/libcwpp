#include <stddef.h>

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace core
{

Frame::Frame(int count)
    : m_count(count), m_children(NULL),
      m_windowManager(NULL)
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

    if (m_windowManager != NULL)
    {
        child->setWindowManager(m_windowManager);
    }

    return true;
}

void Frame::setWindowManager(WindowManager* windowManager)
{
    m_windowManager = windowManager;

    for (int i = 0; i < m_count; i++)
    {
        m_children[i]->setWindowManager(windowManager);
    }
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

} /* namespace core */
} /* namespace libcwpp */
