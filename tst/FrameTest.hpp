#ifndef FRAME_TEST_HPP
#define FRAME_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>

class FrameTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(FrameTest);
    CPPUNIT_TEST(testFrameInvalidSet);
    CPPUNIT_TEST(testRowFrameOneFixed);
    CPPUNIT_TEST(testRowFrameTwoFixed);
    CPPUNIT_TEST(testRowFrameOneDynamic);
    CPPUNIT_TEST(testRowFrameTwoDynamic);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

    void testFrameInvalidSet();
    void testRowFrameOneFixed();
    void testRowFrameTwoFixed();
    void testRowFrameOneDynamic();
    void testRowFrameTwoDynamic();
}; /* class FrameTest */

#endif /* FRAME_TEST_HPP */
