#ifndef GRAPHS_GRAPH_HPP
#define GRAPHS_GRAPH_HPP

#include <string>
#include <vector>

#include "node.hpp"

class Graph {
    public:
        Graph();
        void addNode(const Node& node);
        void connect(const Node& nodeA, const Node& nodeB);
        std::string toString() const;
        std::string getAdjacencyMatrix();

    private:
        std::vector<Node> nodes_;
        std::vector<std::vector<float>> adjacency_matrix_;

        void initializeAdjacencyMatrix();
        int findNodeIndex(const Node& node);
};

#endif //GRAPHS_GRAPH_HPP
