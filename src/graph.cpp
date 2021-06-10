#include <array>
#include "graph.hpp"

#include "node.hpp"

void graph::addNode(const node& node) {
    this->nodes_.push_back(node);
}

std::string graph::toString() const {
    std::stringstream stream;

    stream << "graph {" << std::endl;

    for (node n : this->nodes_) {
        stream << n.toString() << std::endl;
    }

    stream << "}";

    return stream.str();
}