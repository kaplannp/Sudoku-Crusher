CC = g++
TEST_LIBS = -lboost_unit_test_framework

run: main
	./main

runtest: test
	./test

test: sudokuLib.o SudokuBoard.o test.o
	$(CC) $? -o $@ $(TEST_LIBS)

main: main.o sudokuLib.o SudokuBoard.o
	$(CC) $? -o $@

test.o:
	$(CC) -c test.cpp -lboost_unit_test_framework -o test.o

%.o: %.c
	$(CC) -c -o $< $@ 

clean:
	rm -f *.o && rm -f main && rm -f test
