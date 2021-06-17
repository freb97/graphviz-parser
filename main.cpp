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
    std::string line;

    bool inputParsed = false;
    bool edgeInputMode = false;

    while (!inputParsed) {
        getline(std::cin, line);

        if (line.length() == 0) {
            inputParsed = true;
        }

        if (line.length() < 3) {
            if (std::isdigit(line[0]) == 1) {
                int size = std::stoi(line);
                graph = new Graph(size);
            }
            else if (line == "E") {
                edgeInputMode = true;
            }
        }
        else if (line.length() >= 3) {
            if (!edgeInputMode && line.length() >= 7) {
                std::string name = line.substr(2, 2);
                std::string shape = line.substr(0, 1) == "H" ? "box" : "circle";
                float x = std::stoi(line.substr(5, 1));
                float y = std::stoi(line.substr(7, 1));

                Node* node = new Node(name, shape, x, y);
                graph->addNode(*node);
            }
            else {
                int nodeIndexA = std::stoi(line.substr(0, 1));
                int nodeIndexB = -1;

                if (line.length() == 3) {
                    nodeIndexB = std::stoi(line.substr(2, 1));
                }
                else if (line.length() == 4) {
                    nodeIndexB = std::stoi(line.substr(2, 2));
                }

                if (nodeIndexB != -1) {
                    graph->connect(nodeIndexA, nodeIndexB);
                }
                else {
                    std::cout << "Error while parsing node connection at: " << line << std::endl;
                }
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
