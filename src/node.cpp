#include <vector>
#include <sstream>

#include "node.hpp"

/**
 * Class constructor.
 *
 * @param name The name of the node.
 * @param value The vector value of the node.
 */
Node::Node(const std::string& name, const std::vector<float>& value)
{
    this->name_ = name;
    this->value_ = value;
}

/**
 * Class constructor.
 *
 * @param name The name of the node.
 * @param value The vector value of the node.
 * @param shape The shape of the node in a graph.
 */
Node::Node(const std::string& name, const std::vector<float>& value, const std::string& shape)
{
    this->name_ = name;
    this->value_ = value;
    this->shape_ = shape;
}

/**
 * Converts the node data to a string for graphviz.
 *
 * @return The node data as string.
 */
std::string Node::toString()
{
    std::stringstream stream;

    stream << this->name_ << " [pos=\"";

    for (int i = 0; i < this->value_.size(); i++) {
        stream << this->value_[i];

        if (i != this->value_.size() - 1) {
            stream << ",";
        }
    }

    stream << "!\"";

    if (!this->shape_.empty()) {
        stream << ",shape=" << this->shape_;
    }

    stream << "]";

    return stream.str();
}

/**
 * Gets the name of the node.
 *
 * @return The nodes' name.
 */
std::string Node::getName() {
    return this->name_;
}

/**
 * Gets the value of the node.
 *
 * @return The nodes' value.
 */
std::vector<float> Node::getValue() {
    return this->value_;
}

/**
 * Gets the shape of the node.
 *
 * @return The nodes' shape.
 */
std::string Node::getShape() {
    return this->shape_;
}

/**
 * Equal to operator overload function for comparing two nodes.
 *
 * @param nodeA The first node to compare.
 * @param nodeB The second node to compare.
 *
 * @return True if equal, false if not equal.
 */
bool operator ==(Node nodeA, Node nodeB)
{
    return (nodeA.getName() == nodeB.getName() &&
            nodeA.getValue() == nodeB.getValue() &&
            nodeA.getShape() == nodeB.getShape());
}

/**
 * Not equal to operator overload function for comparing two nodes.
 *
 * @param nodeA The first node to compare.
 * @param nodeB The second node to compare.
 *
 * @return False if equal, true if not equal.
 */
bool operator !=(Node nodeA, Node nodeB)
{
    return !(nodeA == nodeB);
}