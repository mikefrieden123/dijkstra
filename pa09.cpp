// Do not to edit this file.

#include "MyGraph.h"
#include "import_problem.h"
#include "import_graph.h"
#include "dijkstra.h"

int main()
{
    // Import graph grabs input via cin, only the information about the graph in the top of the file,
    // leaving the question/problem part still on cin for later.
    MyGraph *g = import_graph();

    // By taking in the remainder of information on the cin buff,
    // import problem just grabs the comma-stripped problem specification line,
    // and feeds in that string to dijkstra.
    // g is the graph pointer
    string problem_statement = import_problem();
    cout << dijkstra(g, problem_statement) << endl;

    delete g;

    return 0;
}
