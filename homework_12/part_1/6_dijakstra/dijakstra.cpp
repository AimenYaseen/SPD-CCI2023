using namespace std;

#include<list>
#include <queue>
#include <iostream>
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
typedef pair<int, int> Pair;

class Graph
{
    int V; 
    list<Pair>* adjList;

public:
    Graph(int v)
    {
        V = v;
        adjList = new list<Pair>[V];
    }

    void addEdge(int v1, int v2, int w)
    {
        adjList[v1].push_back({v2, w});
    }

    void printGraph()
    {
        for(int i = 0; i < V; i++)
        {
            for(auto n: adjList[i])
                cout << "(" << i << " " << n.first << " " << n.second << ")";
            cout << endl;
        }
        cout << endl;
    }

    void shortestPath(int s)
    {
        vector<int> dist(V, INF);
        dist[s] = 0;

        // priority queue to get smallest distance
        priority_queue<Pair, vector<Pair>, greater<Pair>> p;
        p.push({0, s});

        while(!p.empty())
        {
            int v = p.top().second;
            p.pop();

            for(auto pair: adjList[v])
            {
                int u = pair.first, w = pair.second, d = w + dist[v];

                if(dist[u] > d)
                {
                    p.push({d, u});
                    dist[u] = d;
                }
            }
        }

         // Print shortest distances stored in dist[]
        printf("Vertex Shortest Distance from Source '0'\n");
        for (int i = 0; i < V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
        }
};


int main()
{
    int V = 7;
    Graph g(V);
 
    // make edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 10);
    g.addEdge(3, 5, 15);
    g.addEdge(4, 6, 2);
    g.addEdge(5, 6, 6);

    // print graph
    g.printGraph();

    // get shortest distance
    g.shortestPath(0);
}