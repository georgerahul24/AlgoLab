cmake_minimum_required(VERSION 3.26)
project(Graph)

set(CMAKE_CXX_STANDARD 23)

add_executable(Graph main.cpp
        Graph.hpp
        BFS.hpp
        DFS.hpp
        TopologicalSorting.hpp
        ConnectedGraph1.hpp
        ConnectedGraph2.hpp
        Bipartite.hpp
        SCC.hpp
        UndirectedGraphWithWeights.hpp
        Prims.hpp
        Kurskal'sWithLinkedLIst.hpp
        DoublyLinkedList.hpp
        Kruska'swithUnionByRank.hpp
        Dijstra's.hpp
        UndirectedGraphWithWeightsVer2.hpp)
