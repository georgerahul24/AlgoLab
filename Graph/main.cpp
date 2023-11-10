#include "BellmanFord.hpp"

int main() {

    bool negativeCycle;
    BellmanFord t("/Users/gr/Desktop/AlgoLab/Graph/Graph3.txt",&negativeCycle);

    printf("%s\n",negativeCycle?"There is a negative cycle":"There is no negative cycle");

    return 0;
}
