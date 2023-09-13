using namespace std;

#include <map>
#include <vector>


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, vector<int>> adjList;
        
        // undirected graph
        for(auto edge: edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int n = edges.size();
        for(auto pair: adjList)
        {
            if(pair.second.size() == n)
                return pair.first;
        }

        return -1;
    }
};