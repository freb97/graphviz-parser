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
node* parseInput(const std::string& input)
{
    if (input.length() < 7) return nullptr;

    std::string type;
    std::string name;
    float x;
    float y;

    type = input.at(0);
    name = input.substr(2, 2);
    x = std::stof(input.substr(5, 1));
    y = std::stof(input.substr(7, 1));

    type = type == "H" ? "box" : "circle";

    return new node(name, std::vector<float>{x, y}, type);
}

/**
 * Main function.
 *
 * @return The exit state of the program.
 */
int main()
{
    int nodeCount;
    std::cin >> nodeCount;

    graph g = graph();

    for (int i = 0; i <= nodeCount; i++) {
        std::string row;
        std::getline(std::cin, row);

        node* n = parseInput(row);

        if (n != nullptr) {
            g.addNode(*n);
        }
    }

    std::cout << std::endl << std::endl << g.toString() << std::endl;

    return EXIT_SUCCESS;
}