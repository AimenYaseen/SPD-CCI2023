using namespace std;

#include <vector>
#include <iostream>

// define pair
typedef pair<int, int> Pair;

// struct to store src or dest i.e. edges
struct Edges
{
    int s, d, w;
};

class WeightedGraph
{
    vector<vector<Pair>> adjList;

public:
    // default Constructor
    WeightedGraph(vector<Edges> const &edges, int n)
    {
        // resize the vector so that we can access its indices
        adjList.resize(n);

        // index will represent node
        // inner vector will represent neghbours and their weights
        for(auto edge: edges)
            adjList[edge.s].push_back({edge.d, edge.w});
    }

    void printGraph()
    {
        int n = adjList.size();
        for(int i = 0; i < n; i++)
        {
            for(auto v: adjList[i])
                cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
            cout << endl;
        }

        cout << endl;
    }
};


int main()
{
    vector<Edges> edges = {
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    };

    WeightedGraph g(edges, 6);
    g.printGraph();
}