using namespace std;

#include <list>
#include <stack>
#include <iostream>
#include <bits/stdc++.h>


class Graph
{
    int V; // number of vertices
    list<int>* adjList; // array of lists

    void topologicalSortHelper(int v, stack<int>& Stack, int visited[])
    {
        // set current vertex as visited
        visited[v] = true;

        list<int>::iterator it;
        for(it = adjList[v].begin(); it != adjList[v].end(); it++)
        {
            if(!visited[*it])
                topologicalSortHelper(*it, Stack, visited);
        }

        // push the vertices which have no paths left
        Stack.push(v);
    }

public:
    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int v1, int v2)
    {
        adjList[v1].push_back(v2);
    }

    void printGraph()
    {
        cout << endl;

        for(int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for(auto n: adjList[i])
                cout << n << " ";
            cout << endl;
        }
        cout << endl;
    }

    void topologicalSort()
    {
        stack<int> Stack;
        
        // initialize visited array to false
        int visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // call topological sort for every non visited vertex
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
               topologicalSortHelper(i, Stack, visited); 
        }

        // Print contents of stack
        while (!Stack.empty()) 
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
    }
};

int main()
{
    Graph g(6);

    // add edges
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // print graph
    g.printGraph();

    // 
    cout << endl << "Topological Sort" << endl;
    g.topologicalSort();
}