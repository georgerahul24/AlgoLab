#include "UndirectedGraphWithWeights.hpp"
#include "vector"

using namespace std;

class Prims {
public:


    bool inList(Edge *edge, list<Vertex *> *vertices) {

        for (auto vertex: *vertices) {
            if (edge->u == vertex || edge->v == vertex) return true;
        }
        return false;

    }

    bool inList(Vertex *ver, list<Vertex *> *vertices) {

        for (auto vertex: *vertices) {
            if (ver == vertex) return true;
        }
        return false;

    }

    Edge *findMinEdge(list<Edge *> *edges, list<Vertex *> *verticesInS) {
        int min = INT32_MAX;
        Edge *minEdge = nullptr;

        for (auto edge : *edges) {
            if (inList(edge->u, verticesInS) && !inList(edge->v, verticesInS) && edge->weight < min) {
                minEdge = edge;
                min = edge->weight;
            }
            if (inList(edge->v, verticesInS) && !inList(edge->u, verticesInS) && edge->weight < min) {
                minEdge = edge;
                min = edge->weight;
            }
        }
        return minEdge;
    }

    void cut(list<Edge *> *SC, list<Vertex *> *verticesInS) {
        auto it = SC->begin();


        while (it != SC->end()) {

            if (inList((*it)->u, verticesInS) && inList((*it)->v, verticesInS)) {
                it = SC->erase(it);
            }
            ++it;
        }
    }


    Prims(const string &filename) {
        UndirectedGraphWithWeights G(filename);
        G.printAdjacencyMatrix();
        G.createEdges();
        list<Edge *> SC; // S complement
        for (Edge edge: G.edges) {
            SC.push_back(new Edge(edge)); //Copying to SC
        }
        list<Edge *> S; // S
        list<Vertex *> verticesInS;

        int numberOfEdges = 0;
        verticesInS.push_back(&G.vertices[0]);
        while (numberOfEdges < G.n - 1 && !SC.empty()) {
            //printEdges(&SC);
            Edge *minEdge = findMinEdge(&SC, &verticesInS);
            S.push_back(minEdge);
            verticesInS.push_back(minEdge->v);
            verticesInS.push_back(minEdge->u);
            cut(&SC, &verticesInS);
            numberOfEdges++;

           // printf("----------\n");

        }
        printEdges(&S);

    }

    void printEdges(list<Edge *> *S) {

        for (auto edge: *S) {
            printf("%d -> %d (%d)\n", edge->v->value, edge->u->value, edge->weight);

        }
    }
};