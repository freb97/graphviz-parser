#include <array>
#include <iostream>
#include <cassert>

#include "src/node.hpp"
#include "src/graph.hpp"

/**
 * Main function.
 *
 * @return The exit state of the program.
 */
int main()
{
    Graph graph = Graph();

    // Create nodes
    Node* nodeA = new Node("XF", "circle", 0, 0);
    Node* nodeB = new Node("ZF", "box", 0, 0);
    Node* nodeC = new Node("XB", "circle", 2, 0);
    Node* nodeD = new Node("KL", "box", 0, 2);

    // Add nodes to graph
    graph.addNode(*nodeA);
    graph.addNode(*nodeB);
    graph.addNode(*nodeC);
    graph.addNode(*nodeD);

    // Get node indexes in graph
    int nodeIndexA = graph.getNodeIndex(*nodeA);
    int nodeIndexB = graph.getNodeIndex(*nodeB);
    int nodeIndexC = graph.getNodeIndex(*nodeC);
    int nodeIndexD = graph.getNodeIndex(*nodeD);

    // Connect nodes
    graph.connect(nodeIndexA, nodeIndexB);
    graph.connect(nodeIndexA, nodeIndexD);
    graph.connect(nodeIndexC, nodeIndexD);

    // Test node connection
    assert(graph.areConnected(nodeIndexA, nodeIndexB));
    assert(graph.areConnected(nodeIndexA, nodeIndexD));
    assert(graph.areConnected(nodeIndexC, nodeIndexD));

    // Output the adjacency matrix
    std::string adjacencyMatrix = graph.getAdjacencyMatrix();
    std::string edgeList = graph.getEdgeList();

    std::cout << adjacencyMatrix << std::endl << std::endl;
    std::cout << edgeList << std::endl << std::endl;

    std::cout << graph.toString() << std::endl;

    return EXIT_SUCCESS;
}