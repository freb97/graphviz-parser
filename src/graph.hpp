#ifndef GRAPHS_GRAPH_HPP
#define GRAPHS_GRAPH_HPP

#include <string>
#include <vector>

#include "node.hpp"

class Graph {
    public:
        Graph(int size);
        void addNode(const Node& node);
        void connect(int indexA, int indexB);
        bool areConnected(int indexA, int indexB);
        int getNodeIndex(const Node& node);
        std::string getShortestPaths(std::size_t source) const;
        std::string getGraphvizData() const;
        std::string getAdjacencyMatrix();
        std::string getEdgeList() const;

    private:
        std::vector<Node> nodes_;
        std::vector<std::vector<float>> adjacency_matrix_;

        void initializeAdjacencyMatrix(int size);
        bool checkNodeIndex(int index);
        int getClosestNode(const std::vector<float>& distances, std::vector<bool> visited) const;
};

#endif //GRAPHS_GRAPH_HPP
