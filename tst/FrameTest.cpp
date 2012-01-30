#include <boost/test/unit_test.hpp>

#include "TestHelpers.hpp"

#include <libcwpp/layout/RowFrame.hpp>

struct RowFrameFixture
{
    libcwpp::layout::RowFrame frame;
};

BOOST_FIXTURE_TEST_CASE(TestRowFrameOneFixed, RowFrameFixture)
{
    boost::shared_ptr<TestFrame> tst1(new TestFrame(libcwpp::core::Size(1, INT_MAX, 1, 1)));
    frame.add(tst1);
    frame.layout(0, 0, 80, 25);

    BOOST_REQUIRE(tst1->m_layoutCalled);
    BOOST_CHECK_EQUAL(0, tst1->m_x);
    BOOST_CHECK_EQUAL(0, tst1->m_y);
    BOOST_CHECK_EQUAL(80, tst1->m_width);
    BOOST_CHECK_EQUAL(1, tst1->m_height);
}

BOOST_FIXTURE_TEST_CASE(TestRowFrameTwoFixed, RowFrameFixture)
{
    boost::shared_ptr<TestFrame> tst1(new TestFrame(libcwpp::core::Size(1, INT_MAX, 3, 3)));
    boost::shared_ptr<TestFrame> tst2(new TestFrame(libcwpp::core::Size(1, INT_MAX, 2, 2)));
    frame.add(tst1);
    frame.add(tst2);
    frame.layout(0, 0, 80, 25);

    BOOST_REQUIRE(tst1->m_layoutCalled);
    BOOST_CHECK_EQUAL(0, tst1->m_x);
    BOOST_CHECK_EQUAL(0, tst1->m_y);
    BOOST_CHECK_EQUAL(80, tst1->m_width);
    BOOST_CHECK_EQUAL(3, tst1->m_height);

    BOOST_REQUIRE(tst2->m_layoutCalled);
    BOOST_CHECK_EQUAL(0, tst2->m_x);
    BOOST_CHECK_EQUAL(3, tst2->m_y);
    BOOST_CHECK_EQUAL(80, tst2->m_width);
    BOOST_CHECK_EQUAL(2, tst2->m_height);
}

BOOST_FIXTURE_TEST_CASE(TestRowFrameOneDynamic, RowFrameFixture)
{
    boost::shared_ptr<TestFrame> tst1(new TestFrame(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX)));
    frame.add(tst1);
    frame.layout(0, 0, 80, 25);

    BOOST_REQUIRE(tst1->m_layoutCalled);
    BOOST_CHECK_EQUAL(0, tst1->m_x);
    BOOST_CHECK_EQUAL(0, tst1->m_y);
    BOOST_CHECK_EQUAL(80, tst1->m_width);
    BOOST_CHECK_EQUAL(25, tst1->m_height);
}

BOOST_FIXTURE_TEST_CASE(TestRowFrameTwoDynamic, RowFrameFixture)
{
    boost::shared_ptr<TestFrame> tst1(new TestFrame(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX)));
    boost::shared_ptr<TestFrame> tst2(new TestFrame(libcwpp::core::Size(1, INT_MAX, 1, INT_MAX)));
    frame.add(tst1);
    frame.add(tst2);
    frame.layout(0, 0, 80, 24);

    BOOST_REQUIRE(tst1->m_layoutCalled);
    BOOST_CHECK_EQUAL(0, tst1->m_x);
    BOOST_CHECK_EQUAL(0, tst1->m_y);
    BOOST_CHECK_EQUAL(80, tst1->m_width);
    BOOST_CHECK_EQUAL(12, tst1->m_height);

    BOOST_REQUIRE(tst2->m_layoutCalled);
    BOOST_CHECK_EQUAL(0, tst2->m_x);
    BOOST_CHECK_EQUAL(12, tst2->m_y);
    BOOST_CHECK_EQUAL(80, tst2->m_width);
    BOOST_CHECK_EQUAL(12, tst2->m_height);
}
