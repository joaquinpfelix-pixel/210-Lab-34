// COMSC-210 | Lab 34 | Joaquin Felix

#include "Graph.h"

int main()
{
    Graph g(7);

    g.addEdge(0,1,12);
    g.addEdge(0,2,8);
    g.addEdge(0,3,21);
    g.addEdge(2,3,6);
    g.addEdge(2,6,2);
    g.addEdge(2,4,4);
    g.addEdge(2,5,5);
    g.addEdge(4,5,6);
    g.addEdge(5,6,6);

    g.printGraph();

    g.dfs(0);
    g.bfs(0);

    return 0;
}