#ifndef GRAPHS_NODE_HPP
#define GRAPHS_NODE_HPP

#include <vector>
#include <sstream>

class Node {
    public:
        Node(const std::string& name, float x, float y);
        Node(const std::string& name, const std::string& shape, float x, float y);
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
