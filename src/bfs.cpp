/**
 * @file bfs.cpp
 * @brief Runs a breadth-first search from Denver and prints the total discovery distance.
 */

#include <iostream>
#include <format>

#include "MatrixGraph.h"

int main()
{
     MatrixGraph graph;
     int total = graph.breadthFirstSearch(DENVER);
     std::cout << std::format("Total discovery distance: {}\n", total);

    return 0;
}
