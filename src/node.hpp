#ifndef GRAPHS_NODE_HPP
#define GRAPHS_NODE_HPP

#include <vector>
#include <sstream>

class node {
    public:
        node(const std::string &name, const std::vector<float>&);
        node(const std::string &name, const std::vector<float> &value, const std::string &shape);
        std::string toString();

    private:
        std::string name_;
        std::vector<float> value_;
        std::string shape_;
};

#endif //GRAPHS_NODE_HPP
