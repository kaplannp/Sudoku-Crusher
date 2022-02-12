#include "sudokuLib.h"
#define BOOST_TEST_MODULE sudoku_test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
// this runs it 'g++ test.cpp  -lboost_unit_test_framework'

BOOST_AUTO_TEST_SUITE( MyFirstTest )

BOOST_AUTO_TEST_CASE( test_case1 )
{
    BOOST_WARN( sizeof(int) < 4 );
}

BOOST_AUTO_TEST_CASE( test_case2 )
{
    BOOST_REQUIRE_EQUAL( 1, 1 );
}

BOOST_AUTO_TEST_CASE( test_header )
{
  sudoku::PredEntry* p = new sudoku::PredEntry();
  //sudoku::PrintHello();
  //BOOST_TEST(p->getD()[0]);
}

BOOST_AUTO_TEST_SUITE_END()
