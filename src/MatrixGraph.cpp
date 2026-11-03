/**
 * @file MatrixGraph.cpp
 * @brief Implementation of MatrixGraph.
 */

#include "MatrixGraph.h"
#include "GraphData.h"

#include <queue>
#include <algorithm>
#include <iostream>
#include <format>

/// Fills both [u][v] and [v][u] since the graph is undirected.
MatrixGraph::MatrixGraph()
{
    for (const Edge& edge : EDGES)
    {
        // Mirrored
        miles[edge.u][edge.v] = edge.miles;
        miles[edge.v][edge.u] = edge.miles;
    }
}

/// Standard queue-based BFS; unvisited neighbors become discovery edges, visited ones cross edges.
int MatrixGraph::breadthFirstSearch(int start)
{
    std::array<bool, NUM_CITIES> visited{};
    std::queue<int> queue;
    int total{0};

    visited[start] = true;
    queue.push(start);

    while (!queue.empty())
    {
        int u{queue.front()};
        queue.pop();

        for (int v : sortedNeighbors(u))
        {
            if (labels[u][v] != EdgeLabel::UNEXPLORED) continue;

            if (!visited[v]) // Discovery Edge
            {
                labels[u][v] = EdgeLabel::DISCOVERY;
                labels[v][u] = EdgeLabel::DISCOVERY;

                visited[v] = true;
                queue.push(v);
                total += miles[u][v];

                std::cout << std::format("Discovery:   {:<15} -> {:<15}", CITY_NAMES[u], CITY_NAMES[v]);
            }
            else             // Cross Edge
            {
                labels[u][v] = EdgeLabel::CROSS;
                labels[v][u] = EdgeLabel::CROSS;

                std::cout << std::format("Cross:       {:<15} -> {:<15}", CITY_NAMES[u], CITY_NAMES[v]);
            }
            std::cout << '\n';
        }
    }

    return total;
}

/// Scans row @p u of the matrix, then sorts by miles from @p u.
std::vector<int> MatrixGraph::sortedNeighbors(int u) const
{
    std::vector<int> result;

    for (int v{0}; v < NUM_CITIES; ++v)
    {
        if (miles[u][v] != 0)
        {
            result.push_back(v);
        }
    }

    std::ranges::sort(result, [this, u](int a, int b){ return miles[u][a] < miles[u][b]; });

    return result;
}
