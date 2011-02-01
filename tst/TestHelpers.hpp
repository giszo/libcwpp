#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

#include <libcwpp/Frame.hpp>

#define TEST_HEADER std::cout << std::endl << __FUNCTION__ << ": " << __FILE__ << ":" <<  __LINE__ << std::endl;

class TestFrame : public libcwpp::Frame
{
  public:
    TestFrame(const libcwpp::Size& size)
        : Frame(0),
          m_x(-1), m_y(-1), m_width(-1), m_height(-1), m_layoutCalled(false),
          m_size(size)
    {}

    libcwpp::Size getSize(void)
    {
        return m_size;
    }

    void layout(int x, int y, int width, int height)
    {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;

        m_layoutCalled = true;
    }

    int m_x;
    int m_y;
    int m_width;
    int m_height;
    bool m_layoutCalled;

    libcwpp::Size m_size;
}; /* class TestFrame */

#endif /* TEST_HELPERS_HPP */
