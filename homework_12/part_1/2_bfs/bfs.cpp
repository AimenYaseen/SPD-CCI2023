using namespace std;

#include <queue>
#include <vector>
#include <iostream>


class Graph
{
    vector<vector<int>> adjList;
    int V; // number of vertices

public:
    Graph(int v)
    {
        V = v;
        adjList.resize(V);
    }

    void addEdge(int v1, int v2)
    {
        adjList[v1].push_back(v2);
    }

    void printGraph()
    {
        for(int i = 0; i < V; i++)
        {
            cout << endl << i << " -> ";

            for(auto v: adjList[i])
                cout << v << " ";
        }

        cout << endl;
    }

    void BFS(int s)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(s);
        visited[s] = true;

        while(!q.empty())
        {
            int v = q.front();
            cout << v << " ";
            q.pop();

            for(auto const& neigh: adjList[v])
            {
                if(visited[neigh])
                    continue;

                visited[neigh] = true;
                q.push(neigh);
            }
        }

        cout << endl;
    }

};

int main()
{
    Graph g(5);

    // add edges for undirected graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 3);

    g.printGraph();
    cout << endl;
    cout << "Breadth First Search" << endl;
    g.BFS(4);
    cout << endl;
}