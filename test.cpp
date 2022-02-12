#include "sudokuLib.h"
#define BOOST_TEST_MODULE sudoku_test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
// this runs it 'g++ test.cpp  -lboost_unit_test_framework'

/*
 * Just tests to make sure boose and header imports work as I expect
 */
BOOST_AUTO_TEST_SUITE( TestBoost )

BOOST_AUTO_TEST_CASE( test_header )
{
  sudoku::PrintHello();
}



BOOST_AUTO_TEST_SUITE_END()


/*
 * Tests SudokuBoard
 */
BOOST_AUTO_TEST_SUITE( TestSudokuBoard )

BOOST_AUTO_TEST_CASE( TestBoardInit ){

  //initialize a board to construct 9x9 with 123456789 as each row
  const size_t size1 = 9;
  short** board1 = new short*[size1];
  for(int i = 0; i < size1; i++){
    board1[i] = new short[size1];
    for(int j = 0; j < size1; j++){
      board1[i][j] = j;
    }
  }
  //initialize a SudokuBoard from that board object
  sudoku::SudokuBoard sBoard1 = sudoku::SudokuBoard(board1, size1);

 //  short** rBoard = sBoard1.getBoard();
 // for(int i = 0; i < sBoard1.getSize(); i++){
 //   for(int j = 0; j < sBoard1.getSize(); j++){
 //     //BOOST_CHECK_EQUAL(rBoard[i][j],board1[i][j]);
 //   }
 // }

  // cleanup dynamic
 // for(int i = 0; i < size1; i++){
 //   delete board1[i];
 // }
 // delete [] board1;
  
}

BOOST_AUTO_TEST_SUITE_END()
