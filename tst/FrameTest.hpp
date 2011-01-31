#ifndef FRAME_TEST_HPP
#define FRAME_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>

class FrameTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( FrameTest );
    CPPUNIT_TEST( testSimple );
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

    void testSimple();
};

#endif

