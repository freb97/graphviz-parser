#include <array>
#include <sstream>

#include "graph.hpp"
#include "node.hpp"

/**
 * Class constructor.
 */
Graph::Graph() {
    initializeAdjacencyMatrix();
}

/**
 * Adds a node to the graphs' node list.
 *
 * @param node The node to add.
 */
void Graph::addNode(const Node& node) {
    this->nodes_.push_back(node);
}

/**
 * Connects two nodes in the adjacency matrix.
 */
void Graph::connect(const Node& nodeA, const Node& nodeB) {

}

/**
 * Converts the graph output to a string.
 *
 * @return The graph output as string data.
 */
std::string Graph::toString() const {
    std::stringstream stream;

    stream << "graph {" << std::endl;

    for (Node node : this->nodes_) {
        stream << "  " << node.toString() << std::endl;
    }

    stream << "}";

    return stream.str();
}

/**
 * Gets the adjacency matrix values as a string stream.
 *
 * @return The adjacency matrix values.
 */
std::string Graph::getAdjacencyMatrix()
{
    std::stringstream output;

    int size = adjacency_matrix_.size();

    for (int i = 0; i < size; i++) {
        for (int ii = 0; ii < size; ii++) {
            output << adjacency_matrix_[i][ii];

            if (ii == size - 1) {
                output << "\n";
            }
            else {
                output << " ";
            }
        }
    }

    return output.str();
}

/**
 * Initializes the adjacency matrix.
 */
void Graph::initializeAdjacencyMatrix() {
    int matrixSize = 5;
    float matrixValue = std::numeric_limits<float>::infinity();

    for (int i = 0; i < matrixSize; i++) {
        std::vector<float> vector;

        for (int ii = 0; ii < matrixSize; ii++) {
            vector.push_back(matrixValue);
        }

        adjacency_matrix_.push_back(vector);
    }
}

/**
 * Searches for a nodes' index in the local nodes array.
 *
 * @param node The node to search for.
 *
 * @return The nodes' index or -1 if not found.
 */
int Graph::findNodeIndex(const Node& node) {
    for (int i = 0; i < this->nodes_.size(); i++) {
        if (this->nodes_[i] == node) {
            return i;
        }
    }

    return -1;
}
