#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Heap.h"
using namespace std;

// best practice:
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0
#define VISITED 4
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Maze {
public:
    Maze(int dim, int p);
    ~Maze();
    void print();
    void solve(); // solve best path
    void generate(); // generate random maze
    int endDistance(int x, int y, int x2, int y2);
    Node* nodeVisited(Node *nodeVisited, Heap *open);
    bool canGoUp(Node *node);
    bool canGoDown(Node *node);
    bool canGoLeft(Node *node);
    bool canGoRight(Node *node);
    void setPath(Node *node);

private:
    int dim;
    int **arr;
    int void_percentage;
    int **matrix;
};