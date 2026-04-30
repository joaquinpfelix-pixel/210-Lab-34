#include "Graph.h"

Graph::Graph(int s)
{
    size = s;
    adj.resize(size);
}

void Graph::addEdge(int u, int v, int weight)
{
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
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

void Graph::dfs_helper(int v, vector<bool>& visited)
{
    visited[v] = true;
    cout << v << " ";

    for (auto &n : adj[v])
    {
        if (!visited[n.first])
            dfs_helper(n.first, visited);
    }
}

void Graph::dfs(int start)
{
    vector<bool> visited(size, false);

    cout << "DFS starting from vertex " << start << ":\n";
    dfs_helper(start, visited);
    cout << endl;
}

void Graph::bfs(int start)
{
    vector<bool> visited(size, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS starting from the vertex " << start << ":\n";

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (auto &n : adj[v])
        {
            if (!visited[n.first])
            {
                visited[n.first] = true;
                q.push(n.first);
            }
        }
    }
    cout << endl;
}

