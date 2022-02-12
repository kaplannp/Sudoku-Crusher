CC = g++
CFLAGS = -g
TEST_LIBS = -lboost_unit_test_framework

run: main
	./main

runtest: test
	./test

test: sudokuLib.o SudokuBoard.o test.o
	$(CC) $? -o $@ $(TEST_LIBS) $(CFLAGS)

main: main.o sudokuLib.o SudokuBoard.o
	$(CC) $? -o $@ $(CFLAGS)

test.o: test.cpp
	$(CC) -c test.cpp -lboost_unit_test_framework -o test.o $(CFLAGS)

%.o: %.c
	$(CC) -c -o $< $@ $(CFLAGS)

clean:
	rm -f *.o && rm -f main && rm -f test
