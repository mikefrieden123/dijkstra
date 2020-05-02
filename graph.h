// As we've been doing all semester, do not edit this h file

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

/* 
 * Writes to a string your (the student author’s) Campus Username in lowercase.
 * Takes as input a pre-existing std::string by reference. 
 * No return value
 */
void get_identity(string &my_id); 


class Graph
{
    public:
        // Get's index of the first neighbor of a node (indexing starts at 0)
        virtual int get_first_neighbor(int vert) = 0;

        // When there are no more neighbors after prev_neigh, return n (number of nodes in the graph)
        virtual int get_next_neighbor(int vert, int prev_neigh) = 0;

        // Returns the number of nodes
        virtual int n_nodes() = 0;

        // Returns the number of edges
        virtual int n_edges() = 0;

        // Sets the weight of an edge
        virtual void set_edge(int v1, int v2, float wght) = 0;

        // Sets edge weight to 0
        virtual void del_edge(int v1, int v2) = 0;

        // Get's the edge weight
        virtual float get_edge(int v1, int v2) = 0;

        // Set a node's (v) bribe cost
        virtual void set_bribe(int v, float bribe) = 0;

        // Get's a node's (v) bribe cost
        virtual float get_bribe(int v) = 0;

        // Set a node (v) name
        virtual void set_node_name(int v, string name) = 0;

        // Get's a nodes (v) name
        virtual string get_node_name(int v) = 0;
};

#endif

