#include "Graph.h"
#include <climits>
#include <queue>

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
    cout << "Campus Navigation Network:\n";
    cout << "================================\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Building " << i << " connects to:\n";

        for (auto &n : adj[i])
        {
            cout << " -> Building " << n.first
                 << " (Distance: " << n.second << " mins)\n";
        }
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

void Graph::shortestPath(int start)
    {
        vector<int> dist(size, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto &n : adj[u])
            {
                int v = n.first;
                int weight = n.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nShortest paths from building " << start << ":\n";

        for (int i = 0; i < size; i++)
        {
            cout << start << " -> " << i << " : " << dist[i] << endl;
        }
    }

