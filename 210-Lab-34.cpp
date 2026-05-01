// COMSC-210 | Lab 34 | Joaquin Felix

#include "Graph.h"

int main()
{
    Graph g(9);

    g.addEdge(0,1,8);
    g.addEdge(0,2,21);
    g.addEdge(1,2,6);
    g.addEdge(1,3,5);
    g.addEdge(1,4,4);
    g.addEdge(2,7,11);
    g.addEdge(2,8,8);
    g.addEdge(3,4,9);
    g.addEdge(5,6,10);
    g.addEdge(5,7,15);
    g.addEdge(5,8,5);
    g.addEdge(6,7,3);
    g.addEdge(6,8,7);

    g.printGraph();

    g.dfs(0);
    g.bfs(0);

    g.shortestPath(0);
    g.primMST();

    return 0;
}