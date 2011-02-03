#include <limits.h>

#include "FrameTest.hpp"
#include "TestHelpers.hpp"

#include <libcwpp/layout/RowFrame.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION(FrameTest);

void
FrameTest::setUp()
{
}

void
FrameTest::tearDown()
{
}

void
FrameTest::testRowFrameOneFixed()
{
    TEST_HEADER;

    TestFrame tst1(libcwpp::core::Size(1, INT_MAX, 1, 1));
    libcwpp::layout::RowFrame frame;
    frame.add(&tst1);
    frame.layout(0, 0, 80, 25);

    CPPUNIT_ASSERT(tst1.m_layoutCalled);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_x);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_y);
    CPPUNIT_ASSERT_EQUAL(80, tst1.m_width);
    CPPUNIT_ASSERT_EQUAL(1, tst1.m_height);
}

void
FrameTest::testRowFrameTwoFixed()
{
    TEST_HEADER;

    TestFrame tst1(libcwpp::core::Size(1, INT_MAX, 3, 3));
    TestFrame tst2(libcwpp::core::Size(1, INT_MAX, 2, 2));
    libcwpp::layout::RowFrame frame;
    frame.add(&tst1);
    frame.add(&tst2);
    frame.layout(0, 0, 80, 25);

    CPPUNIT_ASSERT(tst1.m_layoutCalled);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_x);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_y);
    CPPUNIT_ASSERT_EQUAL(80, tst1.m_width);
    CPPUNIT_ASSERT_EQUAL(3, tst1.m_height);

    CPPUNIT_ASSERT(tst2.m_layoutCalled);
    CPPUNIT_ASSERT_EQUAL(0, tst2.m_x);
    CPPUNIT_ASSERT_EQUAL(3, tst2.m_y);
    CPPUNIT_ASSERT_EQUAL(80, tst2.m_width);
    CPPUNIT_ASSERT_EQUAL(2, tst2.m_height);
}

void
FrameTest::testRowFrameOneDynamic()
{
    TEST_HEADER;

    TestFrame tst1(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    libcwpp::layout::RowFrame frame;
    frame.add(&tst1);
    frame.layout(0, 0, 80, 25);

    CPPUNIT_ASSERT(tst1.m_layoutCalled);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_x);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_y);
    CPPUNIT_ASSERT_EQUAL(80, tst1.m_width);
    CPPUNIT_ASSERT_EQUAL(25, tst1.m_height);
}

void
FrameTest::testRowFrameTwoDynamic()
{
    TEST_HEADER;

    TestFrame tst1(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    TestFrame tst2(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX));
    libcwpp::layout::RowFrame frame;
    frame.add(&tst1);
    frame.add(&tst2);
    frame.layout(0, 0, 80, 24);

    CPPUNIT_ASSERT(tst1.m_layoutCalled);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_x);
    CPPUNIT_ASSERT_EQUAL(0, tst1.m_y);
    CPPUNIT_ASSERT_EQUAL(80, tst1.m_width);
    CPPUNIT_ASSERT_EQUAL(12, tst1.m_height);

    CPPUNIT_ASSERT(tst2.m_layoutCalled);
    CPPUNIT_ASSERT_EQUAL(0, tst2.m_x);
    CPPUNIT_ASSERT_EQUAL(12, tst2.m_y);
    CPPUNIT_ASSERT_EQUAL(80, tst2.m_width);
    CPPUNIT_ASSERT_EQUAL(12, tst2.m_height);
}
