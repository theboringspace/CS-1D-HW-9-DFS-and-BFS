#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <utility>

#include "GraphData.h"

int main()
{
    // Print every edge
    for (const Edge& e : EDGES)
    {
        std::cout << CITY_NAMES[e.u] << " - " << CITY_NAMES[e.v]
                  << " : " << e.miles << '\n';
    }
    std::cout << "\nTotal edges: " << EDGES.size() << "\n\n";

    // Sanity checks
    bool ok = true;

    if (EDGES.size() != 23)
    {
        std::cout << "FAIL: expected 23 edges\n";
        ok = false;
    }

    std::array<bool, NUM_CITIES> seen{};
    std::set<std::pair<int, int>> pairs;
    for (const Edge& e : EDGES)
    {
        seen[e.u] = true;
        seen[e.v] = true;
        if (!pairs.insert({std::min(e.u, e.v), std::max(e.u, e.v)}).second)
        {
            std::cout << "FAIL: duplicate edge " << CITY_NAMES[e.u]
                      << " - " << CITY_NAMES[e.v] << '\n';
            ok = false;
        }
    }
    for (int c = 0; c < NUM_CITIES; ++c)
    {
        if (!seen[c])
        {
            std::cout << "FAIL: " << CITY_NAMES[c] << " has no edges\n";
            ok = false;
        }
    }

    std::cout << (ok ? "All checks passed: 23 edges, all 12 cities connected, no duplicates.\n"
                     : "Some checks FAILED.\n");
    return ok ? 0 : 1;
}
