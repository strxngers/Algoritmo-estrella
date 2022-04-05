#include "Node.h"
#include <stdlib.h>

int main(){
    Node *testNode = new Node(1,1,0,NULL);
    testNode->print();
    Node * testNode2 = new Node(0,0,0,NULL);
    testNode->setPrevious(testNode2);
    testNode2->print();
    return 0;
}