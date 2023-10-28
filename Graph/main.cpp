#include <iostream>

#include "Bipartite.hpp"

int main() {

    bool connected;
    Bipartite t("/Users/gr/Desktop/AlgoLab/Graph/Graph1.txt", &connected);
    printf("The graph is %s Bipartite", connected ? "" : "not");
    return 0;

}
