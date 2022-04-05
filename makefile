all: test1 test2 test3 Main 

test1: Maze.o Node.o Heap.o test_Maze_1.cpp 
	g++ Maze.o Node.o Heap.o test_Maze_1.cpp -o test1

test2: Node.o Heap.o Maze.o test_Heap_1.cpp
	g++ Node.o Heap.o test_Heap_1.cpp -o test2

test3: Node.o test_Node_1.cpp
	g++ Node.o test_Node_1.cpp -o test3

Main: Maze.o Node.o Heap.o Main.cpp
	g++ Maze.o Node.o Heap.o Main.cpp -o main -lm

Maze.o: Maze.cpp Maze.h
	g++ -c Maze.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

run: test1 test2 test3
	./test1
	./test2
	./test3
