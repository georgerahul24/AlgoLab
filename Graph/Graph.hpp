#include <cstdio>

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
        int n, m;
        NodeLinkedList<Vertex> nodeLinkedList;
        nodeLinkedList.add(new Vertex());
        nodeLinkedList.add(new Vertex());

        auto curr = nodeLinkedList.linkedList;

        while (curr->currentNode != nullptr) {
            printf("%d->", curr->currentNode->value);
            curr = curr->nextNode;
        }


    }

    DirectedGraph(int n, int m) {

    }

    void createGraph(int n, int m) {

    }


};