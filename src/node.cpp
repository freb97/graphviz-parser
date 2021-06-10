#include <vector>
#include <sstream>

#include "node.hpp"

node::node(const std::string& name, const std::vector<float>& value)
{
    this->name_ = name;
    this->value_ = value;
}

node::node(const std::string& name, const std::vector<float>& value, const std::string& shape)
{
    this->name_ = name;
    this->value_ = value;
    this->shape_ = shape;
}

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
