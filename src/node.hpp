#ifndef GRAPHS_NODE_HPP
#define GRAPHS_NODE_HPP

#include <vector>
#include <sstream>

class Node {
    public:
        Node(const std::string &name, const std::vector<float>&);
        Node(const std::string &name, const std::vector<float>& value, const std::string &shape);
        std::string toString();
        std::string getName();
        std::vector<float> getValue();
        std::string getShape();

        friend bool operator ==(Node nodeA, Node nodeB);
        friend bool operator !=(Node nodeA, Node nodeB);

    private:
        std::string name_;
        std::vector<float> value_;
        std::string shape_;
};

#endif //GRAPHS_NODE_HPP
