#include <array>
#include <string>
#include <sstream>

#include "graph.hpp"
#include "node.hpp"

/**
 * Class constructor.
 */
Graph::Graph(int size)
{
    initializeAdjacencyMatrix(size);
}

/**
 * Adds a node to the graphs' node list.
 *
 * @param node The node to add.
 */
void Graph::addNode(const Node& node)
{
    this->nodes_.push_back(node);
}

/**
 * Connects two nodes in the adjacency matrix.
 *
 * @param indexA The index of the first node.
 * @param indexB The index of the second node.
 */
void Graph::connect(int indexA, int indexB)
{
    if (checkNodeIndex(indexA) && checkNodeIndex(indexB)) {
        adjacency_matrix_[indexA][indexB] = 1;
        adjacency_matrix_[indexB][indexA] = 1;
    }
}

/**
 * Checks if two nodes are connected in the adjacency matrix.
 *
 * @param indexA The index of the first node.
 * @param indexB The index of the second node.
 *
 * @return True if the nodes are connected, false if not.
 */
bool Graph::areConnected(int indexA, int indexB)
{
    if (checkNodeIndex(indexA) && checkNodeIndex(indexB)) {
        std::vector<float> nodeValueA = this->nodes_[indexA].getValue();
        std::vector<float> nodeValueB = this->nodes_[indexB].getValue();

        return adjacency_matrix_[indexA][indexB] == 1 &&
               adjacency_matrix_[indexB][indexA] == 1;
    }

    return false;
}

/**
 * Gets a nodes' index in the local nodes array.
 *
 * @param node The node to search for.
 *
 * @return The nodes' index or -1 if not found.
 */
int Graph::getNodeIndex(const Node& node)
{
    for (int i = 0; i < this->nodes_.size(); i++) {
        if (this->nodes_[i] == node) {
            return i;
        }
    }

    return -1;
}

/**
 * Converts the graph output to a string.
 *
 * @return The graph output as string data.
 */
std::string Graph::toString() const
{
    std::stringstream output;

    output << "graph {" << std::endl;

    for (Node node : this->nodes_) {
        output << "  " << node.toString() << std::endl;
    }

    int size = adjacency_matrix_.size();

    for (int i = 0; i < size; i++) {
        for (int ii = i; ii < size; ii++) {
            float value = adjacency_matrix_[i][ii];

            if (value > 0 && value < std::numeric_limits<float>::infinity()) {
                output << "  " << this->nodes_[i].getName() << " -- " << this->nodes_[ii].getName();

                if (i != size - 1) {
                    output << std::endl;
                }
            }
        }
    }

    output << "}";

    return output.str();
}

/**
 * Gets the adjacency matrix values as a string.
 *
 * @return The adjacency matrix values as string.
 */
std::string Graph::getAdjacencyMatrix()
{
    std::stringstream output;

    int size = adjacency_matrix_.size();

    for (int i = 0; i < size; i++) {
        for (int ii = 0; ii < size; ii++) {
            float value = adjacency_matrix_[i][ii] == 1 ? 1 : 0;
            output << value;

            if (ii == size - 1) {
                output << std::endl;
            }
            else {
                output << " ";
            }
        }
    }

    return output.str();
}

/**
 * Gets a representation of the adjacency matrix as an edge list.
 *
 * @return The edge list as a string.
 */
std::string Graph::getEdgeList() const
{
    std::stringstream output;

    int size = adjacency_matrix_.size();

    for (int i = 0; i < size; i++) {
        for (int ii = i; ii < size; ii++) {
            float value = adjacency_matrix_[i][ii];

            if (value > 0 && value < std::numeric_limits<float>::infinity()) {
                output << "[" << i + 1 << "] -- [" << ii + 1 << "]";

                if (i != size - 1) {
                    output << std::endl;
                }
            }
        }
    }

    return output.str();
}

/**
 * Initializes the adjacency matrix.
 */
void Graph::initializeAdjacencyMatrix(int size)
{
    float matrixValue = std::numeric_limits<float>::infinity();

    for (int i = 0; i < size; i++) {
        std::vector<float> vector;

        for (int ii = 0; ii < size; ii++) {
            vector.push_back(matrixValue);
        }

        adjacency_matrix_.push_back(vector);
    }
}

/**
 * Checks if a value exists at a given index in the local nodes array.
 *
 * @param index The index to check.
 *
 * @return True if a value exists at the index, false if its out of array bounds.
 */
bool Graph::checkNodeIndex(int index)
{
    return index >= 0 && index < this->nodes_.size();
}
