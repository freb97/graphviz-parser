#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <sstream>

#include "src/node.hpp"
#include "src/graph.hpp"

/**
 * Parses graph input, adds and connects nodes.
 *
 * @return The filled graph.
 */
Graph parseInput()
{
    Graph* graph;

    std::stringstream output;

    bool inputParsed = false;
    bool edgeInputMode = false;

    while (!inputParsed) {
        std::string lineInput;
        getline(std::cin, lineInput);
        std::stringstream line;
        line << lineInput;

        if (lineInput.length() == 0) {
            inputParsed = true;
        }

        if (lineInput.length() < 3) {
            if (std::isdigit(lineInput[0]) == 1) {
                int size = std::stoi(lineInput);
                graph = new Graph(size);
            }
            else if (lineInput == "E") {
                edgeInputMode = true;
            }
        }
        else if (lineInput.length() >= 3) {
            if (!edgeInputMode && lineInput.length() >= 7) {
                std::string name = lineInput.substr(2, 2);
                std::string shape = lineInput.substr(0, 1) == "H" ? "box" : "circle";

                float x = std::stoi(lineInput.substr(5, 1));
                float y = std::stoi(lineInput.substr(7, 1));

                Node* node = new Node(name, shape, x, y);
                graph->addNode(*node);
            }
            else {
                int nodeIndexA;
                int nodeIndexB;

                line >> nodeIndexA;
                line >> nodeIndexB;

                graph->connect(nodeIndexA, nodeIndexB);
            }
        }
    }

    return *graph;
}

/**
 * Main function.
 *
 * @param argc The argument count.
 * @param argv The argument values.
 *
 * @return The exit state of the program.
 */
int main(int argc, char** argv)
{
    Graph graph = parseInput();

    if (argc >= 2) {
        if (strcmp(argv[1], "-g") == 0) {
            std::cout << graph.toString();
        }
        else if (strcmp(argv[1], "-a") == 0) {
            std::cout << graph.getAdjacencyMatrix();
        }
        else if (strcmp(argv[1], "-e") == 0) {
            std::cout << graph.getEdgeList();
        }
    }
    else {
        std::cout << graph.toString();
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
