#include <array>
#include <iostream>
#include <vector>

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

    float x = std::stof(input.substr(5, 1));
    float y = std::stof(input.substr(7, 1));
    std::vector position = std::vector<float>{x, y};

    std::string type;
    type = input.at(0);
    type = type == "H" ? "box" : "circle";

    return new Node(name, position, type);
}

/**
 * Main function.
 *
 * @return The exit state of the program.
 */
int main()
{
    Graph graph = Graph();

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

    return EXIT_SUCCESS;
}