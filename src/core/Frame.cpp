/*
 * Window manager library for console applications.
 *
 * Copyright (c) 2011  Peter Hajdu, Zoltan Kovacs
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stddef.h>

#include <libcwpp/core/Frame.hpp>
#include <libcwpp/core/WindowManager.hpp>

namespace libcwpp
{
namespace core
{

Frame::Frame(void)
    : m_windowManager(NULL)
{
}

Frame::~Frame()
{
}

bool Frame::add(const boost::shared_ptr<Frame>& child)
{
    m_children.push_back(child);

    if (m_windowManager)
        child->setWindowManager(m_windowManager);

    invalidateLayout();

    return true;
}

bool Frame::insert(size_t index, const boost::shared_ptr<Frame>& child)
{
    m_children.insert(m_children.begin() + index, child);

    if (m_windowManager)
        child->setWindowManager(m_windowManager);

    invalidateLayout();

    return true;
}

bool Frame::set(size_t index, const boost::shared_ptr<Frame>& child)
{
    if (index >= m_children.size())
        return false;

    boost::shared_ptr<Frame> old = m_children[index];
    m_children[index] = child;

    if (m_windowManager)
    {
        old->setWindowManager(NULL);
        child->setWindowManager(m_windowManager);
    }

    invalidateLayout();

    return true;
}

void Frame::setWindowManager(WindowManager* windowManager)
{
    m_windowManager = windowManager;

    for (std::vector< boost::shared_ptr<Frame> >::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
        (*it)->setWindowManager(windowManager);
}

void Frame::paint()
{
    for (std::vector< boost::shared_ptr<Frame> >::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
        (*it)->paint();
}

void Frame::refresh()
{
    for (std::vector< boost::shared_ptr<Frame> >::const_iterator it = m_children.begin();
         it != m_children.end();
         ++it)
        (*it)->refresh();
}

void Frame::invalidateLayout()
{
    if (m_windowManager)
        m_windowManager->pushEvent(WindowManager::E_LAYOUT_CHANGED);
}

} /* namespace core */
} /* namespace libcwpp */
