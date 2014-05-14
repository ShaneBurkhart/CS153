all: run

compile:
	clang++ treetester.cpp
	g++ treetester.cpp

run: compile
	./a.out

memory: compile
	valgrind --leak-check=yes ./a.out
