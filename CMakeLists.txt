cmake_minimum_required(VERSION 3.19)

project(graphs VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)

add_executable(graphs
        main.cpp
        src/node.cpp
        src/node.hpp
        src/graph.cpp
        src/graph.hpp
)