#include <sstream>

#include <libcwpp/util/StringUtils.hpp>

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
