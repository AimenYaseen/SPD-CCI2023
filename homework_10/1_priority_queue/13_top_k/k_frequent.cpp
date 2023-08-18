using namespace std;

#include<vector>
#include<queue>
#include <iostream>
#include<unordered_map>


class Solution {
public:
    class Compare
    {
        public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
        {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for(auto num: nums)
            freqMap[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;

        for(auto pair: freqMap)
            maxHeap.push(pair);

        vector<int> freq_elements;

        while(!maxHeap.empty() && freq_elements.size() < k)
        {
            freq_elements.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return freq_elements;
    }
};