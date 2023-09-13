using namespace std;

#include <list>
#include <stack>
#include <iostream>
#include <bits/stdc++.h>


class Graph
{
    int V;
    list<int>* adjList;

    void setVisitedFalse(bool visited[])
    {
        for (int i = 0; i < V; i++)
            visited[i] = false;
    }

    void topologicalSort(int v, stack<int>& Stack, bool visited[])
    {
        // set current vertex as visited
        visited[v] = true;

        for(auto neigh: adjList[v])
        {
            if(!visited[neigh])
                topologicalSort(neigh, Stack, visited);
        }

        // push the vertices which have no paths left
        Stack.push(v);
    }

    Graph transpose()
    {
        Graph g(V);
        // traverse every vertex
        for (int s = 0; s < V; s++) 
        {
            // add its neighbors as new vertex in new graph
            // and make the vertex its neighbor
            list<int>::iterator it;
            for(it = adjList[s].begin(); it != adjList[s].end(); ++it)
                g.adjList[*it].push_back(s);
        }
        return g;
    }

    void DFS(int v, bool visited[])
    {
        // set visited true
        visited[v] = true;
        cout << v << " ";

        for(auto neigh: adjList[v])
        {
            if(!visited[neigh])
                DFS(neigh, visited);
        }
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

    void SCC()
    {
        stack<int> Stack;
        
        // initialize visited array to false
        bool visited[V];
        setVisitedFalse(visited);

        // call topological sort for every non visited vertex
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
               topologicalSort(i, Stack, visited); 
        }

        // take transpose
        Graph graph = transpose();
        // set visited to false
        setVisitedFalse(visited);

        while(!Stack.empty())
        {
            int v = Stack.top();
            Stack.pop();

            if(!visited[v])
            {
                graph.DFS(v, visited);
                cout << endl;
            }
        }
    }
};

int main() 
{
    Graph g(8);

    // add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    g.addEdge(6, 7);

    // print graph
    g.printGraph();

    // 
    cout << endl << "Strongly Connected Componenets" << endl;
    g.SCC();
}