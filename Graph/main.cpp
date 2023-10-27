#include <iostream>

#include "ConnectedGraph2.hpp"

int main() {

    bool connected;
    ConnectedGraph2 t("/Users/gr/Desktop/AlgoLab/Graph/Graph1.txt", &connected);
    printf("The graph is %s connected", connected ? "" : "not");
    return 0;

}
