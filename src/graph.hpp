#ifndef GRAPHS_GRAPH_HPP
#define GRAPHS_GRAPH_HPP

#include <string>
#include <vector>

#include "node.hpp"

class Graph {
    public:
        Graph();
        void addNode(const Node& node);
        void connect(int indexA, int indexB);
        bool areConnected(int indexA, int indexB);
        int getNodeIndex(const Node& node);
        std::string toString() const;
        std::string getAdjacencyMatrix();
        std::string getEdgeList() const;

    private:
        std::vector<Node> nodes_;
        std::vector<std::vector<float>> adjacency_matrix_;

        void initializeAdjacencyMatrix();
        bool checkNodeIndex(int index);
};

#endif //GRAPHS_GRAPH_HPP
