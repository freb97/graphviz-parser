#include <array>
#include <iomanip>
#include <string>
#include <sstream>

#include "graph.hpp"
#include "node.hpp"

/**
 * Class constructor.
 */
Graph::Graph(int size)
{
    if (size < 1) {
        throw "Error: Graph size has to be bigger than 0.";
    }

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
 * Gets the shortest paths to each node from a given source node.
 *
 * @param source The node to start at.
 *
 * @return The shortest paths representation as a string.
 */
std::string Graph::getShortestPaths(std::size_t source) const
{
    if (source >= this->nodes_.size()) {
        return "Error: Source node index out of bounds.";
    }

    constexpr float notConnected = std::numeric_limits<float>::infinity();
    std::vector<float> distances(this->nodes_.size(), notConnected);
    distances[source] = 0.0f;

    const std::size_t noPredecessor = this->nodes_.size();
    std::vector<std::size_t> predecessors(this->nodes_.size(), noPredecessor);

    std::vector<bool> visited(this->nodes_.size(), false);
    distances[source] = 0;

    for (int i = 0; i < this->nodes_.size() - 1; i++) {
        int closestNodeIndex = getClosestNode(distances, visited);
        visited[closestNodeIndex] = true;

        for (int ii = 0; ii < this->nodes_.size(); ii++) {
            float closestNodeDistance = distances[closestNodeIndex];
            float nodeConnected = this->adjacency_matrix_[closestNodeIndex][ii];

            if (!visited[ii] && nodeConnected && closestNodeDistance != notConnected &&
                closestNodeDistance + nodeConnected < distances[ii]) {
                distances[ii] = closestNodeDistance + nodeConnected;
                predecessors[ii] = closestNodeIndex;
            }
        }
    }

    std::stringstream output;

    for (float distance : distances) {
        output << std::setw(2);

        if (distance != notConnected) {
            output << distance << " ";
        }
        else {
            output << "--" << " ";
        }
    }

    output << std::endl << std::endl;

    for (std::size_t predecessor : predecessors) {
        output << std::setw(2);

        if (predecessor != noPredecessor) {
            output << predecessor << " ";
        }
        else {
            output << "--" << " ";
        }
    }

    return output.str();
}

/**
 * Gets the graph output as graphviz compatible string.
 *
 * @return The graph output as string data.
 */
std::string Graph::getGraphvizData() const
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
                output << " " << std::endl;
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

/**
 * Gets the closest node of all unvisited nodes.
 *
 * @param distances The distances to all nodes from the source node.
 * @param visited The visited state of the nodes.
 *
 * @return The index of the next closest node.
 */
int Graph::getClosestNode(const std::vector<float>& distances, std::vector<bool> visited) const {
    int min = std::numeric_limits<int>::max();
    int min_index;

    for (int i = 0; i < distances.size(); i++) {
        if (visited[i] == 0 && distances[i] <= min) {
            min = distances[i];
            min_index = i;
        }
    }

    if (min_index >= distances.size()) {
        min_index = distances.size() - 1;
    }

    return min_index;
}
