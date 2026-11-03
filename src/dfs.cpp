#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "GraphData.h"

int dfs(int start)
{
    struct Adj
    {
        int to;
        int miles;
        int id;
    };

    std::vector<std::vector<Adj>> adj(NUM_CITIES);
    for (std::size_t i = 0; i < EDGES.size(); ++i)
    {
        adj[EDGES[i].u].push_back({EDGES[i].v, EDGES[i].miles, static_cast<int>(i)});
        adj[EDGES[i].v].push_back({EDGES[i].u, EDGES[i].miles, static_cast<int>(i)});
    }
    for (auto& list : adj)
    {
        std::sort(list.begin(), list.end(),
                  [](const Adj& a, const Adj& b) { return a.miles < b.miles; });
    }

    std::vector<bool> visited(NUM_CITIES, false);
    std::vector<bool> labeled(EDGES.size(), false);
    std::vector<std::string> discoveryEdges;
    std::vector<std::string> backEdges;
    int total = 0;

    std::function<void(int)> visit = [&](int u)
    {
        visited[u] = true;
        for (const Adj& e : adj[u])
        {
            if (labeled[e.id])
            {
                continue;
            }
            labeled[e.id] = true;

            if (!visited[e.to])
            {
                discoveryEdges.push_back(CITY_NAMES[u] + " -> " + CITY_NAMES[e.to] + " : DISCOVERY");
                total += e.miles;
                visit(e.to);
            }
            else
            {
                backEdges.push_back(CITY_NAMES[u] + " -> " + CITY_NAMES[e.to] + " : BACK");
            }
        }
    };
    visit(start);

    std::cout<< "\n" << "DISCOVERY_EDGES" << "\n" << "\n";
    for (const std::string& edge : discoveryEdges)
    {
        std::cout << edge << '\n';
    }
    std::cout << "\n" << "\n" << "BACK_EDGES" << "\n" << "\n";
    for (const std::string& edge : backEdges)
    {
        std::cout << edge << '\n';
    }

    return total;
}