#include "Heap.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int n=20;
    srand(time(NULL));
    Heap h(n);

    // inserting random numbers
    for(int i = 0; i < n; i++) {
        int val=rand()%n;
        Node *node = new Node(i, i, val, NULL);
        cout<<"inserting "<<val<<endl;
        h.insert(node);
        delete node;
    }

    // printing heap
    cout << "The Heap" <<endl;
    h.print();

    // extraccting all element from heap, shoud all appears in order
    cout << "Ordered number:" << endl;
    for(int i=0;i<n; i++){
        Node *node = h.pull();
        cout<<"pulling "<<node->getValue()<<endl;
    }
 }