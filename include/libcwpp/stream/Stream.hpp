#ifndef LIBCWPP_STREAM_STREAM_HPP
#define LIBCWPP_STREAM_STREAM_HPP

#include <string>

namespace libcwpp
{
namespace stream
{

class Flush {};

class Stream
{
  public:
    virtual Stream& operator<<(char c) = 0;
    virtual Stream& operator<<(int i) = 0;
    virtual Stream& operator<<(const char* s) = 0;
    virtual Stream& operator<<(const std::string& s) = 0;

    virtual Stream& operator<<(const Flush& f) = 0;
}; /* class Stream */

} /* namespace stream */
} /* namespace libcwpp */

#endif /* LIBCWPP_STREAM_STREAM_HPP */
