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

### Nodes

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

### Edges

To add connections between nodes, append the input with the
edge connection indicator "E" and list the names of nodes
to connect.

Example:

3<br>
H LL 1 0<br>
L TO 1 1<br>
H LP 0 2<br>
E<br>
0 1<br>
2 0

This will output the following graphviz data:

graph {<br>
&nbsp;&nbsp;LL [pos="1,0!",shape=box]<br>
&nbsp;&nbsp;TO [pos="1,1!",shape=circle]<br>
&nbsp;&nbsp;LP [pos="0,2!",shape=box]<br>
&nbsp;&nbsp;LL -- TO<br>
&nbsp;&nbsp;LL -- LP<br>
}

### Program arguments

To output the graphviz data, call the executable with the argument "-g".
This is the standard behaviour and doesn't have to be explicitly stated.

To output the graphs' adjacency matrix, call the executable with the
argument "-a" and to output the graphs' edge list use the argument "-e".

#### Adjacency matrix output

When given the argument -a, the program will output the
adjacency matrix data of the graph.

Example:

3<br>
H LL 1 0<br>
L TO 1 1<br>
H LP 0 2<br>
E<br>
0 1<br>
2 0

This will output the following data:

0 1 1<br>
1 0 0<br>
1 0 0

#### Edge list output

When given the argument -e, the program will output the
edge list data of the graph.

Example:

3<br>
H LL 1 0<br>
L TO 1 1<br>
H LP 0 2<br>
E<br>
0 1<br>
2 0

This will output the following data:

[1] -- [2]<br>
[1] -- [3]
