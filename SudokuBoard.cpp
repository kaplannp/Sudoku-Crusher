#include "sudokuLib.h"
#include <algorithm>

namespace sudoku {

  //PREDENTRY CLASS
  
  PredEntry::PredEntry() {
    for(int i = 0; i < NUM_ELEMENTS; i++)
      d[i] = true;
    deg_freedom = NUM_ELEMENTS;
  }
  
  //SUDOKUBOARD CLASS
  //PUBLIC METHODS
  
  //John Stratton, Why is it that I cannot make this short const**?
  //TODO figure out what is happening
  SudokuBoard::SudokuBoard(short** board, const size_t size) : size(size){
    
    // allocate space for board
    this->board = new short*[size];
    for(int i = 0; i < size; i++)
      this->board[i] = new short[size];
    // copy passed board into board
    std::copy(&board[0][0], &board[0][0]+size*size, &this->board[0][0]);

    //allocate space for predBoard
    predBoard = new PredEntry**[size];
    for(int i = 0; i < size; i++) {
      predBoard[i] = new PredEntry*[size];
      //fill the elements of predBoard
      for(int j = 0; j < size; j++) {
        predBoard[i][j] = new PredEntry();
      }
    }

  }

  SudokuBoard::~SudokuBoard(){

    // the [] is necessary. Without it, we just delete the ptr at that
    // location rather than the array it points to.

    // delete the board
    for(int i = 0; i < size; i++)
      delete [] board[i]; 
    delete [] board;

    //delete the predBoard
    for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
        delete predBoard[i][j];
      }
      delete [] predBoard[i];
    }
    delete [] predBoard;
  }

  short** sudoku::SudokuBoard::getBoard() const{
    return board;
  }

  const size_t sudoku::SudokuBoard::getSize() const{
    return size;
  }

  
}
