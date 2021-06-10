#include <vector>
#include <sstream>

#include "node.hpp"

/**
 * Class constructor.
 *
 * @param name The name of the node.
 * @param value The vector value of the node.
 */
node::node(const std::string& name, const std::vector<float>& value)
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
node::node(const std::string& name, const std::vector<float>& value, const std::string& shape)
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
std::string node::toString()
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
