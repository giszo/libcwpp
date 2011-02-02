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
