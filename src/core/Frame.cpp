#include <stddef.h>

#include <libcwpp/core/Frame.hpp>

namespace libcwpp
{
namespace core
{

Frame::Frame(void)
    : m_windowManager(NULL)
{
}

Frame::~Frame(void)
{
}

bool Frame::add(Frame* child)
{
    m_children.push_back(child);
    return true;
}

bool Frame::insert(size_t index, Frame* child)
{
    m_children.insert(m_children.begin() + index, child);
    return true;
}

void Frame::setWindowManager(WindowManager* windowManager)
{
    m_windowManager = windowManager;

    for (std::vector<Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        (*it)->setWindowManager(windowManager);
    }
}

void Frame::paint(void)
{
    for (std::vector<Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        (*it)->paint();
    }
}

void Frame::refresh(void)
{
    for (std::vector<Frame*>::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
    {
        (*it)->refresh();
    }
}

} /* namespace core */
} /* namespace libcwpp */
