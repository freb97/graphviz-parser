#include <array>

#include "graph.hpp"
#include "node.hpp"

/**
 * Adds a node to the graphs' node list.
 *
 * @param node The node to add.
 */
void graph::addNode(const node& node) {
    this->nodes_.push_back(node);
}

/**
 * Converts the graph output to a string.
 *
 * @return The graph output as string data.
 */
std::string graph::toString() const {
    std::stringstream stream;

    stream << "graph {" << std::endl;

    for (node n : this->nodes_) {
        stream << n.toString() << std::endl;
    }

    stream << "}";

    return stream.str();
}