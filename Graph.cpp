#include "Graph.h"

Graph::Graph(int s)
{
    size = s;
    adj.resize(size);
}

void Graph::addEdge(int u, int v, int weight)
{
    adj[u].push_back({v, weight});
    adj[v].push_back({v, weight});
}

void Graph::printGraph()
{
    cout << "Graph adjacency list:\n";

    for (int i = 0; i < size; i++)
    {
        cout << i << " --> ";
        for (auto &n : adj[i])
        {
            cout << "(" << n.first << ", " << n.second << ") ";
        }
        cout << endl;
    }
}

