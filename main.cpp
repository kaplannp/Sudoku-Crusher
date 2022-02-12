#include "sudokuLib.h"
#include <iostream>

int main(){
  std::cout << "yep, I can run" << std::endl;
  sudoku::PrintHello();
  
  // generate an array for testing purposes
  // Is this really the best way?
  const size_t size1 = 9;
  short** board1 = new short*[size1];
  for(int i = 0; i < size1; i++){
    board1[i] = new short[size1];
    for(int j = 0; j < size1; j++){
      board1[i][j] = j;
    }
  }

  sudoku::SudokuBoard sBoard1 = sudoku::SudokuBoard(board1, size1);

  // cleanup dynamic
  for(int i = 0; i < size1; i++){
    delete board1[i];
  }
  delete [] board1;

  return 0;
}
