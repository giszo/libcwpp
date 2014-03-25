#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

#include <libcwpp/core/Frame.hpp>
#include <libcwpp/core/Canvas.hpp>

class TestFrame : public libcwpp::core::Frame
{
  public:
    TestFrame(const libcwpp::core::Size& size)
        : Frame(),
          m_x(-1), m_y(-1), m_width(-1), m_height(-1), m_layoutCalled(false),
          m_size(size)
    {}

    libcwpp::core::Size getSize()
    {
        return m_size;
    }

    void layout(int x, int y, int width, int height) override
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

    libcwpp::core::Size m_size;
}; /* class TestFrame */

class TestCanvas : public libcwpp::core::Canvas
{
  public:
    enum Command
    {
        CLEAR,
        PRINT
    };

    struct Instruction
    {
        Instruction(Command cmd, int x = 0, int y = 0, const std::string& data = "")
            : m_cmd(cmd), m_x(x), m_y(y), m_data(data)
        {}

        Command m_cmd;
        int m_x;
        int m_y;
        std::string m_data;
    };

    void clear() override
    {
        m_instructions.push_back(Instruction(CLEAR));
    }

    void print(int x, int y, const char* format, ...) override
    {
        char buffer[1024];

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        m_instructions.push_back(Instruction(PRINT, x, y, buffer));
    }

    std::vector<Instruction> m_instructions;
};

#endif /* TEST_HELPERS_HPP */
