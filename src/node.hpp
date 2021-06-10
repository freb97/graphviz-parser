#ifndef GRAPHS_NODE_HPP
#define GRAPHS_NODE_HPP

class node {
    public:
        node(const std::string &name, const std::vector<float>&);
        std::string toString();

    private:
        std::string name;
        std::vector<float> value;
};

#endif //GRAPHS_NODE_HPP
