#include <string>
#include <vector>
#include <sstream>

#include "node.hpp"

node::node(const std::string& name, const std::vector<float>& value)
{
    this->name = name;
    this->value = value;
}

std::string node::toString()
{
    std::stringstream stream;

    stream << this->name << " [pos=\"";

    for (int i = 0; i < this->value.size(); i++) {
        stream << this->value[i];

        if (i != this->value.size() - 1) {
            stream << ",";
        }
    }

    stream << "!\"]";

    return stream.str();
}
