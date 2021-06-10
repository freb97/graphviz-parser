# Graphviz Parser

A rudimentary parser for graphviz output.

## Build

### CMake

Create the project cmake files

`cmake .`

Build the executable(s)

`make` (or `cmake --build .`)

## Run

### Graphs

Run the parser

`./build/graphs`

## Usage

First, enter the number of nodes to add to a graph.
For each node to add, specify the type:

* H - "Fast Node"
* L - "Slow Node"

Then specify the name and values of the node:
* "Name 3 9"

Example:

3<br>
H LL 1 0<br>
L TO 1 1<br>
H LP 0 2

This will output the following graphviz data:

graph {<br>
&nbsp;&nbsp;LL [pos="1,0!",shape=box]<br>
&nbsp;&nbsp;TO [pos="1,1!",shape=circle]<br>
&nbsp;&nbsp;LP [pos="0,2!",shape=box]<br>
}
