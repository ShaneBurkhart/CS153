all: run memory

compile:
	clang++ smalltester.cpp
	g++ largetester.cpp

run: compile
	./a.out

memory: compile
	valgrind --leak-check=yes ./a.out
