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

#include <libcwpp/core/Size.hpp>

namespace libcwpp
{
namespace core
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

} /* namespace core */
} /* namespace libcwpp */
