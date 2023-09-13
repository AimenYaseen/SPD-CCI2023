using namespace std;

#include <queue>
#include <vector>
#include <iostream>


class Solution {
    struct Compare
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
        {
            return a.second < b.second;
        }
    };
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // create a max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> p_score;

        int n = score.size();
        for(int i = 0; i < n; i++)
            p_score.push({i, score[i]});

        vector<string> ranks(n, "");

        int i = 1;

        for(int i=1; i <= n; i++)
        {
            int index = p_score.top().first;
            p_score.pop();

            if( i == 1)
                ranks[index] = "Gold Medal";
            else if(i == 2)
                ranks[index] = "Silver Medal";
            else if(i == 3)
                ranks[index] = "Bronze Medal";
            else
                ranks[index] = to_string(i);
        }

        return ranks;
    }
};