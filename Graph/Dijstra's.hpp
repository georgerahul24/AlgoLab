#include "UndirectedGraphWithWeightsVer2.hpp"
#include "vector"
#include "set"
#include "queue"

using namespace std;


class Dijstra {

    struct Comparator {
        bool operator()(const Vertex *a, const Vertex *b) const {
            return a->d > b->d;
        }
    };

    void printSet(set<Vertex *> *s) {
        for (auto ver: *s) {
            printf("|%d-(%d)| -> ", ver->value, ver->d);
        }
        printf("\n");
    }

    void printQueue(vector<Vertex *> *s) {
        for (auto ver: *s) {
            printf("%d[%d] -> ", ver->value, ver->d);
        }
        printf("\n");
    }


public:
    Dijstra(const string &filename) {
        UndirectedGraphWithWeights G(filename);
        G.createEdges();
        G.createAdjacencyListFromMatrix();
        G.printAdjacencyMatrix();
        G.printAdjacencyList();

        vector<Vertex *> pq;
        set<Vertex *> notVisited;
        set<Vertex *> visted;

        for (int i = 0; i < G.n; i++) {
            notVisited.insert(&G.vertices[i]);
            pq.push_back(&G.vertices[i]);
        }

        G.vertices[0].d = 0;
        Vertex *parent = nullptr;

        make_heap(pq.begin(), pq.end(), Comparator());

        while (!pq.empty()) {
            Vertex *ver = pq.at(0);
            for (adjacencyListEdge v: (G.adjacencyList->at(ver->value))) {
                v.vertex->d = min(v.vertex->d, ver->d+v.weight);
            }

            printQueue(&pq);
            pq.erase(pq.begin());
            make_heap(pq.begin(), pq.end(), Comparator());
        }

        for (Vertex i: G.vertices) {
            printf("%d : %d\n", i.value, i.d);
        }


    }


};