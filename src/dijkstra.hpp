#ifndef GRAPHS_DIJKSTRA_HPP
#define GRAPHS_DIJKSTRA_HPP

#include <vector>

#include "node.hpp"

class Dijkstra {
    public:
        static std::vector<std::vector<int>> getAllDistances(std::vector<Node> nodes, int sourceIndex);
};

#endif //GRAPHS_DIJKSTRA_HPP
