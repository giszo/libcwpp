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

#include <sstream>

#include "StringUtils.hpp"

namespace libcwpp
{
namespace util
{

bool StringUtils::toInt(const std::string& s, int& n)
{
    std::stringstream ss;
    ss << s;
    ss >> n;

    return !ss.fail();
}

std::string StringUtils::toString(int n)
{
    std::stringstream ss;
    ss << n;

    return ss.str();
}

std::deque<std::string> StringUtils::tokenize(const std::string& s, const std::string delim)
{
    std::deque<std::string> tokens;

    std::string::size_type i;
    std::string::size_type j = 0;
    std::string::size_type l = delim.size();

    while ((i = s.find(delim, j)) != std::string::npos)
    {
        tokens.push_back(s.substr(j, i - j));
        j = i + l;
    }

    if (j < s.size())
    {
        tokens.push_back(s.substr(j, s.size() - j));
    }

    return tokens;
}

} /* namespace util */
} /* namespace libcwpp */
