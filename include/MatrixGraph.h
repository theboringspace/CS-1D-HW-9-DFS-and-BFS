/**
 * @file MatrixGraph.h
 * @brief Adjacency-matrix graph of the 12 cities, with breadth-first search.
 */

#pragma once

#include <array>
#include <vector>

#include "GraphData.h"

/// Classification of an edge during a traversal.
enum class EdgeLabel { UNEXPLORED, DISCOVERY, CROSS };

/**
 * @brief Undirected, weighted city graph stored as an adjacency matrix.
 *
 * Built from ::EDGES; a weight of 0 means no edge between two cities.
 */
class MatrixGraph
{
    public:
        /// @brief Builds the symmetric distance matrix from ::EDGES.
        MatrixGraph();

        /**
         * @brief Runs BFS from @p start, printing each edge as Discovery or Cross.
         *
         * Neighbors are visited closest-first (see sortedNeighbors()).
         *
         * @param start Index of the starting city (e.g. ::DENVER).
         * @return Total miles of all discovery edges.
         */
        int breadthFirstSearch(int start);

    private:
        std::array<std::array<int, NUM_CITIES>, NUM_CITIES> miles{};        ///< Distance between cities; 0 = no edge.
        std::array<std::array<EdgeLabel, NUM_CITIES>, NUM_CITIES> labels{}; ///< Label for each edge, mirrored.

        /**
         * @brief Gets the neighbors of @p u, sorted by distance (closest first).
         * @param u Index of the city.
         * @return Indices of the cities adjacent to @p u.
         */
        std::vector<int> sortedNeighbors(int u) const;
};
