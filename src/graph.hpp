#ifndef GRAPHS_GRAPH_HPP
#define GRAPHS_GRAPH_HPP

#include <string>
#include <vector>

#include "node.hpp"

class graph {
    public:
        void addNode(const node& node);
        std::string toString() const;

    private:
        std::vector<node> nodes_;
};

#endif //GRAPHS_GRAPH_HPP
