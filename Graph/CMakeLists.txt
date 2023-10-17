cmake_minimum_required(VERSION 3.26)
project(Graph)

set(CMAKE_CXX_STANDARD 23)

add_executable(Graph main.cpp
        Graph.hpp
        BFS.hpp
        DFS.hpp)
