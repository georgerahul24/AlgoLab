#include "Graph.hpp"
#include "queue"

using namespace std;

class DFS {
public:
    DirectedGraph *G = nullptr;
    int time = 0;

    explicit DFS(const string &filename) {

        G = new DirectedGraph(filename);
        G->createAdjacencyListFromMatrix();
        printf("\nDFS\n");

        for (int i = 0; i < G->n; i++) {
            G->vertices[i].color = 0;
            G->vertices[i].d = INFINITY;
            G->vertices[i].f = 0;
        }


        for (int i = 0; i < G->n; i++) {
            if (G->vertices[i].color == 0) {
                DFS_VISIT(&G->vertices[i]);
            }
        }

    }

    void DFS_VISIT(Vertex *u) {
        u->d = ++time;
        u->color = 1;

        Node<Vertex> *curr = G->adjacencyList[u->value].linkedList;

        while (curr->currentNode != nullptr) {
            Vertex *v = curr->currentNode;
            if (v->color == 0) {
                v->pi = u;
                DFS_VISIT(v);
            }
            curr = curr->nextNode;
        }
        u->color = 2;
        time++;
        u->f = time;
        printf("%d ", u->value);
    }
};