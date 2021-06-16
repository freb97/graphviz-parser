#include <array>
#include <iostream>
#include <cassert>

#include "src/node.hpp"
#include "src/graph.hpp"

/**
 * Parses user input for graph data.
 *
 * @param input The given user input as a string.
 *
 * @return node if input could be parsed, else nullptr.
 */
Node* parseInput(const std::string& input)
{
    if (input.length() < 7) return nullptr;

    std::string name = input.substr(2, 2);

    std::string type;
    type = input.at(0);
    type = type == "H" ? "box" : "circle";

    float x = std::stof(input.substr(5, 1));
    float y = std::stof(input.substr(7, 1));

    return new Node(name, type, x, y);
}

/**
 * Main function.
 *
 * @return The exit state of the program.
 */
int main()
{
    Graph graph = Graph();

    /*
        std::string adjacencyMatrix = graph.getAdjacencyMatrix();
        std::cout << adjacencyMatrix << std::endl;

        int nodeCount;
        std::cin >> nodeCount;

        for (int i = 0; i <= nodeCount; i++) {
            std::string row;
            std::getline(std::cin, row);

            Node* node = parseInput(row);

            if (node != nullptr) {
                graph.addNode(*node);
            }
        }

        std::cout << std::endl << std::endl << graph.toString() << std::endl;

        L XF 0 0
        H ZF 1 0
        L XB 2 0
        H KL 0 2
    */

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

    return EXIT_SUCCESS;
}