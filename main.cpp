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
Graph* parseInput()
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
                std::string shape;
                line >> shape;
                shape = shape == "H" ? "box" : "circle";

                std::string name;
                line >> name;

                float x;
                line >> x;

                float y;
                line >> y;

                Node* node = new Node(name, shape, x, y);

                if (graph) {
                    graph->addNode(*node);
                }
            }
            else {
                int nodeIndexA;
                int nodeIndexB;

                line >> nodeIndexA;
                line >> nodeIndexB;

                if (graph) {
                    graph->connect(nodeIndexA, nodeIndexB);
                }
            }
        }
    }

    return graph;
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
    Graph* graph = nullptr;

    try {
        graph = parseInput();
    }
    catch (const std::exception& exception) {
        std::cout << "Invalid input given. Please try a different format." << std::endl;
        std::cout << std::endl << "Error message: " << exception.what() << std::endl;
    }

    if (!graph) {
        return EXIT_FAILURE;
    }

    if (argc >= 2) {
        if (strcmp(argv[1], "-g") == 0) {
            std::cout << graph->getGraphvizData();
        }
        else if (strcmp(argv[1], "-a") == 0) {
            std::cout << graph->getAdjacencyMatrix();
        }
        else if (strcmp(argv[1], "-e") == 0) {
            std::cout << graph->getEdgeList();
        }
        else if (strcmp(argv[1], "-d") == 0) {
            int startNodeIndex = 0;

            if (argc >= 3) {
                startNodeIndex = std::stoi(argv[2]);
            }

            std::cout << graph->getShortestPaths(startNodeIndex);
        }
    }
    else {
        std::cout << graph->getGraphvizData();
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
