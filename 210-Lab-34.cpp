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

    int choice;

    do
    {
        cout << "\nMenu\n";
        cout << "1. Display graph\n";
        cout << "2. BFS\n";
        cout << "3. DFS\n";
        cout << "4. Shortest path\n";
        cout << "5. MST\n";
        cout << "0. Exit\n";

        cin >> choice;

        switch(choice)
        {
            case 1 : g.printGraph(); break;
            case 2 : g.dfs(0); break;
            case 3 : g.bfs(0); break;
            case 4 : g.shortestPath(0); break;
            case 5 : g.primMST(); break;
            case 0 : cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);
    
    

    return 0;
}