#include "UndirectedGraphWithWeights.hpp"
#include "DoublyLinkedList.hpp"
#include "vector"

using namespace std;


class Kruskal {
public:
    Vertex *getRepresentative(Vertex *vertex, vector<DoublyLinkedList> linkedLists) {
        for (auto linkedList: linkedLists) {
            auto ver = linkedList.find(vertex);
            if (ver != nullptr) {
                return ver->representative;
            }
        }
        return nullptr;
    }


    Kruskal(const string &filename) {
        UndirectedGraphWithWeights G(filename);
        vector<DoublyLinkedList> linkedLists;
        for (int i = 0; i < G.n; i++) {
            auto newDL = DoublyLinkedList();
            newDL.push_back(&G.vertices[i], &G.vertices[i]);
            linkedLists.push_back(newDL);
        }



        DoublyLinkedList::mergeAndChangeRepresentative(&linkedLists.at(0), &linkedLists.at(1));
        DoublyLinkedList::mergeAndChangeRepresentative(&linkedLists.at(0), &linkedLists.at(2));

        linkedLists.erase(linkedLists.begin()+1);
        linkedLists.erase(linkedLists.begin()+1);

        for(auto linked : linkedLists){
            linked.display();
        }
    }

};