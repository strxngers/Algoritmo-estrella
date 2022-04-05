#include "Maze.h"

// Constructor
Maze::Maze(int dim, int p) {
    srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::generate();
    //this->container = new Container(dim);

}

// Elimina un laberinto
Maze::~Maze() {
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

// genera un laberinto y una matriz de las mismas dimensiones, la matriz
// será util para marcar los nodos visitados
void Maze::generate() {
    arr = new int*[dim];    // Maze
    matrix = new int*[dim];  // Matrix
    for (int i = 0; i < dim; i++) { 
        arr[i] = new int[dim];
        matrix[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
            matrix[i][j] = 0;
        }
    }

    // set the entrance and exit
    arr[0][0] = IN_DOOR;
    arr[dim-1][dim-1] = OUT_DOOR;
}


// Imprime el laberinto
void Maze::print(){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(arr[i][j] == 2){
                cout << "S";    // Al encontrar la entrada se pondrá una "S" de "Start"
            }else if(arr[i][j] == 3){
                cout << "E";    // Al encontrar la salida se pondrá una "E" de "End"
            }else if(arr[i][j] == 1){
                cout << "X";    // Las murallas se representan con "X"
            }else if(arr[i][j] == 0){
                cout <<  " ";   // Los caminos se mostrarán como espaciós vacios
            // Al printear por segunda vez después de utilizar solve(), se printea el recorrido
            // que hace hasta la salida
            }else if(arr[i][j] == VISITED){ 
                cout << CYAN << "@" << RESET;   // El camino se verá de color cyan
            }
        }
        cout << "\n";
    }    
}

// Calcula la distancia desde el inicio del laberinto hasta la salida
// *Distacia Manhattan* 
int Maze::endDistance(int x, int y, int x2, int y2){
    int a = abs(x-x2) + abs(y-y2);
    return a;
}

// Revisa si se puede subir de posición dentro del laberinto
bool Maze::canGoUp(Node *node){
    int i = node->get_i();
    int j = node->get_j();
    if(i > 0 && (this->arr[i-1][j] == 0 || this->arr[i-1][j] == 3) 
        && this->matrix[i-1][j] == 0){
        return true;
    }else{
        return false;
    }
}

// Revisa si se puede bajar de posición dentro del laberinto
bool Maze::canGoDown(Node *node){
    int i = node->get_i();
    int j = node->get_j();
    if(i < this->dim-1 && (this->arr[i+1][j] == 0 || this->arr[i+1][j] == 3)  
        && this->matrix[i+1][j] == 0){
        return true;
    }else{
        return false;
    }
}

// Revisa si se puede ir a la izquierda dentro del laberinto
bool Maze::canGoLeft(Node *node){
    int i = node->get_i();
    int j = node->get_j();
    if(j > 0 && (this->arr[i][j-1] == 0 || this->arr[i][j-1] == 3) 
        && this->matrix[i][j-1] == 0){
        return true;
    }else{
        return false;
    }
}

// Revisa si se puede ir a la derecha dentro del laberinto
bool Maze::canGoRight(Node *node){
    int i = node->get_i();
    int j = node->get_j();
    if(j < this->dim-1 && (this->arr[i][j+1] == 0 || this->arr[i][j+1] == 3) 
        && this->matrix[i][j+1] == 0){
        return true;
    }else{
        return false;
    }
}

// Cambia el camino para marcar los nodos visitados
void Maze::setPath(Node *node){
    while(node->getPrevious() != NULL){
        int i = node->get_i();
        int j = node->get_j();
        arr[i][j] = VISITED;
        node = node->getPrevious();
    }
}

// Esta es la función en la que se resuelve el laberinto
// Falta: decir si hay solución o no y yo quiero printear bonito el camino
void Maze::solve(){
    Heap *open = new Heap(this->dim*dim);   // Heap para los abiertos
    Node *start = new Node(0,0,0,NULL);     // Nodo de inicio
    Node *current;      // Nodo actual
    open->insert(start);    
    while(!open->isEmpty()){
        current = open->pull();

        // Se toman las coordenadas del nodo actual
        int nodeI = current->get_i();   
        int nodeJ = current->get_j();
        if(arr[nodeI][nodeJ] == OUT_DOOR){
            //setPath(current);   // Marca el nodo como visitado
            //cout << "Se encontro un camino" << endl;    
            //cout << current->getPath() << endl;
            arr[dim-1][dim-1] = OUT_DOOR;
            open->~Heap();
             
            return;
        }
        if(canGoUp(current)){
            this->matrix[current->get_i()-1][current->get_j()] = 1;   // Se marca el nodo como visitado (cambio de 0 a 1)
            int distance = endDistance(nodeI-1,nodeJ,this->dim-1,this->dim-1);  // Calculo de value
            Node *newNode = new Node(nodeI-1, nodeJ, distance,current); // Se avanza al siguiente nodo
            open->insert(newNode);
        }
        if(canGoDown(current)){
            this->matrix[current->get_i()+1][current->get_j()] = 1;   // Se marca el nodo como visitado (cambio de 0 a 1)
            int distance = endDistance(nodeI+1,nodeJ,this->dim-1,this->dim-1);
            Node *newNode = new Node(nodeI+1, nodeJ, distance,current); 
            open->insert(newNode);
        }
        if(canGoLeft(current)){
            this->matrix[current->get_i()][current->get_j()-1] = 1;   // Se marca el nodo como visitado (cambio de 0 a 1)
            int distance = endDistance(nodeI,nodeJ-1,this->dim-1,this->dim-1);
            Node *newNode = new Node(nodeI, nodeJ-1, distance,current);
            open->insert(newNode);
        }
        if(canGoRight(current)){
            this->matrix[current->get_i()][current->get_j()+1] = 1;   // Se marca el nodo como visitado (cambio de 0 a 1)
            int distance = endDistance(nodeI,nodeJ+1,this->dim-1,this->dim-1);
            Node *newNode = new Node(nodeI, nodeJ+1, distance,current);
            open->insert(newNode);
        }
    }
    cout << "No encontrado" << endl;
} 
