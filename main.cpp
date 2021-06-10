#include <iostream>
#include <vector>

#include "src/node.hpp"

/**
 * Main function
 *
 * @return int
 */
int main() {
    node test = node("Test", std::vector<float>{2.5,6.7});

    std::cout << test.toString() << std::endl;

    return EXIT_SUCCESS;
}
