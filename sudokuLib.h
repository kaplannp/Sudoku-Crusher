#include <cstddef>
#ifndef SUDOKU_LIB_H
#define SUDOKU_LIB_H
//the number of elements for each square (always 10 in Sudoku
#define NUM_ELEMENTS 9

/*
 * sudoko namespace implements useful classes for
 * evaluating the solutions to sudoku puzzles
 */
namespace sudoku {

  /*
   * Attributes:
   *   d is the data, array of bools. True if this entry could be that element
   *   def_freedom is the total number of Trues in d
   */
  class PredEntry {
    private:
      bool d[NUM_ELEMENTS];
      unsigned short deg_freedom;
    public:
      /*
       * Constructer initializes its data array to trues
       * initializes deg_freedom to NUM_ELEMENTS
       */
      PredEntry();

      bool* getD() {return d;};

  };

  /*
   * printHello is a prints "hello world"
   * it's purpose is to help me remember the syntax
   * of how this three file import system works in c++
   * until I've got more functions going.
   */
  void PrintHello();
  class SudokuBoard{
    private:
      short** board; //2x2 array board

      // question here: Would it be clearer to use a struct or typedef?
      PredEntry*** predBoard; // board of predictions
      size_t size; // width of board (same as height)
    public:
      /*
       * constructor initializes the board by copying
       * the array passed into it's board
       * params:
       *   const short[][] board: the sudoku board
       *   const int size: the width of the board (board is assumed square)
       */
      SudokuBoard(const short** board, const size_t size);

      ~SudokuBoard();
      

  };

}

#endif
