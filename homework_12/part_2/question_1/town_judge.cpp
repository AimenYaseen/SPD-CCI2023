using namespace std;

#include <map>
#include <vector>
#include <algorithm>


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<vector<int>> adjList;
        adjList.resize(n);

        for(auto edge:trust)
        {
            adjList[edge[0]-1].push_back(edge[1]-1);
        }

        int judge = -1;

        for(int i = 0; i < n; i++)
        {
            if(adjList[i].empty())
            {
                judge = i;
                break;
            }
        }

        if(judge == -1)
            return -1;

        for(int i = 0; i < n; i++)
        {
            if(i == judge)
                continue;

            auto it = find(adjList[i].begin(), adjList[i].end(),judge);
            if(it == adjList[i].end())
                return -1;
        }

        return judge + 1;
    }
};