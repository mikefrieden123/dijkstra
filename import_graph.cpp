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

    MyGraph *g_temp = new MyGraph;

    g_temp->fillMatrix();
  
    return g_temp;
}

