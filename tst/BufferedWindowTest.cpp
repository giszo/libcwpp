#include <boost/test/unit_test.hpp>

#include <boost/scoped_ptr.hpp>

#include "TestHelpers.hpp"

#define private public
#define protected public

#include <libcwpp/window/BufferedWindow.hpp>

struct BufferedWindowFixture
{
    BufferedWindowFixture()
    {
        m_canvas = new TestCanvas();
        m_window.reset(new libcwpp::window::BufferedWindow(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX), m_canvas));
    }

    size_t GetInstructionCount()
    { return m_canvas->m_instructions.size(); }

    TestCanvas::Command GetCommand(size_t i)
    { return m_canvas->m_instructions[i].m_cmd; }

    TestCanvas* m_canvas;
    boost::scoped_ptr<libcwpp::window::BufferedWindow> m_window;
};

BOOST_FIXTURE_TEST_CASE(TestEmptyBufferedWindow, BufferedWindowFixture)
{
    BOOST_CHECK(m_window->m_lines.empty());
    BOOST_CHECK(!m_window->m_lastLineClosed);

    m_window->paint();
    BOOST_REQUIRE_EQUAL(GetInstructionCount(), 1);
    BOOST_CHECK_EQUAL(GetCommand(0), TestCanvas::CLEAR);
}

BOOST_FIXTURE_TEST_CASE(TestBufferedWindowPainting, BufferedWindowFixture)
{
    // Write hello
    m_window->addText("Hello");
    BOOST_REQUIRE_EQUAL(m_window->m_lines.size(), 1);
    BOOST_CHECK_EQUAL(m_window->m_lines[0], "Hello");
    BOOST_CHECK(!m_window->m_lastLineClosed);

    // Write a new line
    m_window->addText("\n");
    BOOST_REQUIRE_EQUAL(m_window->m_lines.size(), 1);
    BOOST_CHECK_EQUAL(m_window->m_lines[0], "Hello");
    BOOST_CHECK(m_window->m_lastLineClosed);

    // Write some text with a newline at the end
    m_window->addText("World\n");
    BOOST_REQUIRE_EQUAL(m_window->m_lines.size(), 2);
    BOOST_CHECK_EQUAL(m_window->m_lines[0], "Hello");
    BOOST_CHECK_EQUAL(m_window->m_lines[1], "World");
    BOOST_CHECK(m_window->m_lastLineClosed);

    // Test painting
    m_window->paint();
    BOOST_REQUIRE_EQUAL(GetInstructionCount(), 3);
    BOOST_CHECK_EQUAL(GetCommand(0), TestCanvas::CLEAR);
    BOOST_CHECK_EQUAL(GetCommand(1), TestCanvas::PRINT);
    TestCanvas::Instruction& instr1 = m_canvas->m_instructions[1];
    BOOST_CHECK_EQUAL(instr1.m_x, 0);
    BOOST_CHECK_EQUAL(instr1.m_y, 0);
    BOOST_CHECK_EQUAL(instr1.m_data, "Hello");
    BOOST_CHECK_EQUAL(GetCommand(2), TestCanvas::PRINT);
    TestCanvas::Instruction& instr2 = m_canvas->m_instructions[2];
    BOOST_CHECK_EQUAL(instr2.m_x, 0);
    BOOST_CHECK_EQUAL(instr2.m_y, 1);
    BOOST_CHECK_EQUAL(instr2.m_data, "World");
}
