/** 
 * Import one instance of a graph,
 * and save it's features in the graph object.
 * Define the import_graph function here.
 * It should create a dynamically allocated object and return it's address
 * You can change this file, as long as it returns what is needed,
 * and does not break the h file, and returns a pointer to your graph.
 * More details about running this in pa09.cpp
 **/

#include "MyGraph.h"


MyGraph * import_graph()
{
    // where graph_size is n;
    int n;
    MyGraph *g_temp = new MyGraph(n);

    // or 
    // MyGraph *g_temp = new MyGraph;

    // Here: Do import on your g object, using public MyGraph functions.
    // You will need to store the graph data and in the MyGraph.

    return g_temp;
}

