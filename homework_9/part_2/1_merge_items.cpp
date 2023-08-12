using namespace std;

#include<vector>
#include<map>


class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> m;
        vector<vector<int>> mergedV;

        for(auto item: items1)
            m[item[0]] = item[1];

        for(auto item: items2)
            m[item[0]] = m[item[0]] + item[1];

        for(const auto& pair: m)
            mergedV.push_back({pair.first, pair.second});

        return mergedV;
    }
};