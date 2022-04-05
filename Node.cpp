#include "Node.h"

Node::Node() {
    this->i = 0;
    this->j = 0;
    this->value = 0;
    this->depth = -1;
    this->previous = NULL;
}

Node::Node(Node* node) {
    this->i = node->i;
    this->j = node->j;
    this->value = node->value;
    this->depth = node->depth;
    this->previous = node->previous;
}

// Constructor
Node::Node(int i, int j, int value, Node* parent) {
    this->i = i;
    this->j = j;
    this->value = value;
    this->previous = parent;
}

// Elimina un nodo
Node::~Node () {
}

// Obtiene la coordenada i del nodo
int Node::get_i() {
    return this->i;
}

// Obtiene la coordenada j del nodo
int Node::get_j() {
    return this->j;
}

// Obtiene nodo anterior
Node* Node::getPrevious() {
    return this->previous;
}

// Obtiene el value del grupo
int Node::getValue() {
    return this->value;
}

// Cambia el nodo anterior por otro
void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

// Cambia la profundidad
void Node::setDepth(int depth) {
    this->depth = depth;
}

// Retrona si el el nodo anterior es NULL
int Node::isRoot() {
    return this->previous == NULL;
}

// Printea un nodo
void Node::print() {
    cout << "(" << this->i << "," << this->j << ")[" << this->value << "]" << endl;
}

// Obtiene la profundidad
int Node::getDepth() {
    return(this->depth);    
}

// the path from the root to the current node as a string
string Node::getPath() {
    string s="("+to_string(this->i)+","+to_string(this->j)+")";
    if (this->previous != NULL) {
        s=s+this->previous->getPath();
    }
    return(s); 
}