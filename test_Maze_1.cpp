#include "Maze.h"

int main() {
    Maze m(5000, 90);
    //m.print();
    m.solve();
    m.print();
    return 0;

}