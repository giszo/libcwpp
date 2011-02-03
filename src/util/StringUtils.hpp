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

#ifndef LIBCWPP_UTIL_STRINGUTILS_HPP
#define LIBCWPP_UTIL_STRINGUTILS_HPP

#include <deque>
#include <string>

namespace libcwpp
{
namespace util
{

class StringUtils
{
  public:
    static bool toInt(const std::string& s, int& n);

    static std::string toString(int n);

    static std::deque<std::string> tokenize(const std::string& s, const std::string delim);
}; /* class StringUtils */

} /* namespace util */
} /* namespace libcwpp */

#endif /* LIBCWPP_UTIL_STRINGUTILS_HPP */
