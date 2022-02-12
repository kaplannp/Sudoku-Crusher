CC = g++

run: main
	out/main


main: main.cpp sudokuLib.cpp SudokuBoard.cpp
	$(CC) $? -o out/$@

.cpp.o:
	$(CC) -c out/$<

clean:
	rm out/*
