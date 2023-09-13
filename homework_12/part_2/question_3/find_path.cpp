using namespace std;

#include <vector>


class Solution {
    vector<vector<int>> adjList;

    void explore(int v, bool visited[], int Cs[], int c)
    {
        visited[v] = true;
        Cs[v] = c;

        for(auto neigh: adjList[v])
        {
            if(!visited[neigh])
                explore(neigh, visited, Cs, c);
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int components[n];
        bool visited[n];
        int c = 0;

        for(int i = 0; i < n; i++)
            visited[i] = false;

        // resize the vector so that we can access its indices
        adjList.resize(n);

        for(auto edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                explore(i, visited, components, ++c);
        }

        return components[source] == components[destination];
    }
};

int main()
{
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}
    };

    Solution s;
    s.validPath(3, edges, 0, 2);
}