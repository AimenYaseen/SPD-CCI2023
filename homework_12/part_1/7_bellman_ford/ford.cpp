using namespace std;

#include <iostream>
#include <bits/stdc++.h>


typedef pair<int, int> Pair;

struct Edges 
{
    int s, d, w;
};

class WeightedGraph 
{
    vector<vector<Pair>> adjList;

public:
    WeightedGraph(vector<Edges> const& edges, int n) 
    {
        adjList.resize(n);

        for (auto edge : edges)
            adjList[edge.s].push_back({edge.d, edge.w});
    }

    void printGraph() 
    {
        int n = adjList.size();
        for (int i = 0; i < n; i++) 
        {
            for (auto v : adjList[i])
                cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
            cout << endl;
        }
        cout << endl;
    }

    void BellmanFord(int source) 
    {
        int n = adjList.size();
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;

        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                for (auto v : adjList[j]) 
                {
                    int u = j;
                    int dest = v.first;
                    int weight = v.second;

                    if (dist[u] != INT_MAX && dist[u] + weight < dist[dest])
                        dist[dest] = dist[u] + weight;
                }
            }
        }

        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << ": " << dist[i] << '\n';
        
    }
};

int main() 
{
    vector<Edges> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -2}
    };

    WeightedGraph g(edges, 5);
    g.printGraph();

    int source = 0; // Source vertex
    g.BellmanFord(source);

}