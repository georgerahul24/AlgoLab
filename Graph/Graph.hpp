#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
struct Node {
    T *currentNode;
    Node<T> *nextNode;
};


template<typename T>
class NodeLinkedList {
public:

    int length = 0;
    Node<T> *linkedList
            = new Node<T>{.currentNode = nullptr, .nextNode = nullptr};


    void add(T *node) {
        auto *_node = new Node<T>();
        _node->currentNode = node;
        _node->nextNode = linkedList;
        linkedList = _node;
        length++;
    }


};

struct Vertex {
    int value = -1;
    int status = -1;

    Vertex() {

    }

    Vertex(int value, int status) {
        this->value = value;
        this->status = status;
    }
};

struct Edge {
    Vertex *u = nullptr;
    Vertex *v = nullptr;
};

class DirectedGraph {
public:
    int n = 0;
    int m = 0;
    int **adjacencyMatrix = nullptr;
    NodeLinkedList<Vertex> *adjacencyList = nullptr;

    DirectedGraph() {
        cout << "Enter the number of Vertices: ";
        cin >> n;

        cout << "Enter the number of Edges: ";
        cin >> m;
    }

    explicit DirectedGraph(const string &filename) {
        std::ifstream f(filename);
        string line;


        std::getline(f, line);
        std::istringstream iss(line);
        iss >> this->n >> this->m;
        adjacencyMatrix = new int *[n];

        for (int i = 0; i < n; i++) {
            adjacencyMatrix[i] = new int[m];
        }

        cout << "Edges Detected: " << endl;
        int tm=m;
        while (tm--) {

            std::getline(f, line);
            std::istringstream iss(line);
            int startnode, endnode;
            iss >> startnode >> endnode;
            cout << startnode << "->" << endnode << endl;

            adjacencyMatrix[startnode][endnode]=1;

        }
        printAdjacencyMatrix();


    }

    DirectedGraph(int n, int m) {

    }

    void createGraph(int n, int m) {

    }

    void printAdjacencyMatrix() {
        printf("|  ");
        for (int i = 0; i < n; i++) {
            printf("%d_", i);
        }

        printf("\n");


        for (int i = 0; i < n; i++) {
            printf("%d| ", i);
            for (int j = 0; j < n; j++) {
                printf("%d ", adjacencyMatrix[i][j]);
            }

            printf("\n");
        }
    }


};