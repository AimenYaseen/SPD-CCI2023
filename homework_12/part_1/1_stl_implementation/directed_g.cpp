using namespace std;

#include <vector>
#include <iostream>

// struct to store src or dest i.e. edges
struct Edges
{
    int src, des;
};

class DirectedGraph
{
    vector<vector<int>> adjList;

public:
    // default Constructor
    DirectedGraph(vector<Edges> const &edges, int n)
    {
        // resize the vector so that we can access its indices
        adjList.resize(n);

        // index will represent node
        // inner vector will represent neghbours
        for(auto edge: edges)
            adjList[edge.src].push_back(edge.des);
    }

    void printGraph()
    {
        int n = adjList.size();
        for(int i = 0; i < n; i++)
        {
            cout << endl << i << " -> ";

            for(auto v: adjList[i])
                cout << v << " ";
        }

        cout << endl;
    }
};


int main()
{
    vector<Edges> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };

    DirectedGraph g(edges, 6);
    g.printGraph();
}