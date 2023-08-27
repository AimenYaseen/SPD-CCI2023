using namespace std;

#include <map>
#include <iostream>
#include <bits/stdc++.h>


class Graph
{
    map<int, bool> visited;
    map<int, list<int>> adjList;

public:
    void addEdge(int v1, int v2)
    {
        adjList[v1].push_back(v2);
    }

    void printGraph()
    {
        for(auto pair: adjList)
        {
            cout << pair.first << " -> ";
            for(auto l: pair.second)
            {
                cout << l << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void DFS(int s)
    {
        // preorder traversal
        cout << s << " ";
        visited[s] = true;

        for(auto v: adjList[s])
        {
            if(!visited[v])
                DFS(v);
        }
    }
};

int main()
{
    Graph g;

    // add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // print graph
    g.printGraph();

    // DFS 
    cout << "Depth First Search started from 0" << endl;
    g.DFS(0);
    cout << endl;

}