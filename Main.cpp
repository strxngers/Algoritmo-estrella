#include <iostream>
#include "Maze.h"
#include <time.h>
#include <ctime>

using namespace std;

int main(){
    Maze m = Maze(1000, 90);  
    unsigned t0, t1;
    double time;
    double aTime;
    for(int i = 0; i < 100; i++){
        t0 = clock();
        m.solve();
        t1 = clock();
        time = (double(t1 - t0) / CLOCKS_PER_SEC);
        cout << "Solved in: " << time << "[s]" << endl;
        aTime += time;
        m.generate();
    }
    cout << "El tiempo promedio es: " << aTime/100 << "[s]" << endl;
    return 0;
}