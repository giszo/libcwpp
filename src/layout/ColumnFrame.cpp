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

#include <limits.h>

#include <algorithm>

#include <libcwpp/layout/ColumnFrame.hpp>

namespace libcwpp
{
namespace layout
{

ColumnFrame::ColumnFrame()
    : Frame()
{
}

libcwpp::core::Size ColumnFrame::getSize()
{
    int minWidth = 0;
    int maxWidth = 0;
    int minHeight = 0;
    int maxHeight = 0;

    for (ChildTable::const_iterator it = m_children.begin(); it != m_children.end(); ++it)
    {
        libcwpp::core::Size size = (*it)->getSize();

        minWidth += size.minWidth();

        if ((maxWidth == INT_MAX) ||
            (size.maxWidth() == INT_MAX))
            maxWidth = INT_MAX;
        else
            maxWidth += size.maxWidth();

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
    for (ChildTable::const_iterator it = m_children.begin(); it != m_children.end(); ++it)
    {
        libcwpp::core::Size size = (*it)->getSize();

        if (size.isWidthDynamic())
            dynamicCount++;
        else
            remainingWidth -= size.minWidth();
    }

    if (dynamicCount > 0)
        dynamicWidth = remainingWidth / dynamicCount;
    else
        dynamicWidth = 0;

    /* Do the actual layout work. */
    for (ChildTable::const_iterator it = m_children.begin(); it != m_children.end(); ++it)
    {
        boost::shared_ptr<libcwpp::core::Frame> child = *it;
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
