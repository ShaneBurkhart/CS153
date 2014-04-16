all: run

compile:
	clang++ *.cpp
	g++ *.cpp

run: compile
	./a.out

memory: compile
	valgrind --leak-check=yes ./a.out
