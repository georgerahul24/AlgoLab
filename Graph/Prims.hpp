#include "UndirectedGraphWithWeights.hpp"
#include "vector"

using namespace std;

class Prims {
public:
    vector<Edge *> *edges = new vector<Edge *>;

    Prims(const string &filename) {
        UndirectedGraphWithWeights G(filename);
        int i = 0;
        G.printAdjacencyMatrix();
        while (G.vertices[i].color == 0) {
            int minWeight = INT32_MAX, minIndex = 0;
            for (int j = 0; j < G.n; j++) {
                if (minWeight > G.adjacencyMatrix[i][j] && G.vertices[j].color == 0) {
                    minWeight = G.adjacencyMatrix[i][j];
                    minIndex = j;
                }
            }
            G.vertices[i].color = 2;
            if(minWeight==INT32_MAX) break;
            edges->push_back(new Edge(&G.vertices[i], &G.vertices[minIndex], minWeight));
            i = minIndex;
        }

        for (auto edge: *edges) {
            printf("%d -> %d (%d)\n", edge->u->value, edge->v->value, edge->weight);
        }

    }


};