// COMSC-210 | Lab 34 | Joaquin Felix

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Graph
{
    private:
        int size;
        vector<vector<pair<int,int>>> adj;

        void dfs_helper(int v, vector<bool>& visited);

    public:
        Graph(int s);
        
        void addEdge(int u, int v, int weight);
        void printGraph();

        void dfs(int start);
        void bfs(int start);
        void shortestPath(int start);
};

#endif