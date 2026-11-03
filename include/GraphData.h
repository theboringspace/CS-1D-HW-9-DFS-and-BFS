#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
#include <vector>

// City indices 0-11
enum City
{
    SEATTLE = 0,
    SAN_FRANCISCO,
    LOS_ANGELES,
    DENVER,
    CHICAGO,
    KANSAS_CITY,
    DALLAS,
    HOUSTON,
    BOSTON,
    NEW_YORK,
    ATLANTA,
    MIAMI
};

inline constexpr int NUM_CITIES = 12;

// Names in the same order as enum City, so CITY_NAMES[DENVER] == "Denver"
inline const std::vector<std::string> CITY_NAMES = {
    "Seattle",
    "San Francisco",
    "Los Angeles",
    "Denver",
    "Chicago",
    "Kansas City",
    "Dallas",
    "Houston",
    "Boston",
    "New York",
    "Atlanta",
    "Miami"
};

struct Edge
{
    int u;
    int v;
    int miles;
};

// Undirected graph: each edge is listed exactly once
inline const std::vector<Edge> EDGES = {
    {SEATTLE,       SAN_FRANCISCO,  807},
    {SEATTLE,       DENVER,        1331},
    {SEATTLE,       CHICAGO,       2097},
    {SAN_FRANCISCO, DENVER,        1267},
    {SAN_FRANCISCO, LOS_ANGELES,    381},
    {LOS_ANGELES,   DENVER,        1015},
    {LOS_ANGELES,   KANSAS_CITY,   1663},
    {LOS_ANGELES,   DALLAS,        1435},
    {DENVER,        CHICAGO,       1003},
    {DENVER,        KANSAS_CITY,    599},
    {CHICAGO,       KANSAS_CITY,    533},
    {CHICAGO,       NEW_YORK,       787},
    {CHICAGO,       BOSTON,         983},
    {BOSTON,        NEW_YORK,       214},
    {NEW_YORK,      KANSAS_CITY,   1260},
    {NEW_YORK,      ATLANTA,        888},
    {KANSAS_CITY,   ATLANTA,        864},
    {KANSAS_CITY,   DALLAS,         496},
    {DALLAS,        ATLANTA,        781},
    {DALLAS,        HOUSTON,        239},
    {HOUSTON,       ATLANTA,        810},
    {HOUSTON,       MIAMI,         1187},
    {ATLANTA,       MIAMI,          661}
};

#endif // GRAPH_DATA_H
