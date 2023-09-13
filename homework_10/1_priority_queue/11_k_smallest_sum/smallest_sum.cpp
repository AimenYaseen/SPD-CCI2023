using namespace std;

#include <vector>
#include <queue>


class Solution {
    typedef pair<int, pair<int, int>> pr;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pr> maxHeap;

        for(auto num1: nums1)
        {
            for(auto num2: nums2)
            {
                int sum = num1 + num2;
                // push the first k pairs
                if(maxHeap.size() < k)
                    maxHeap.push({sum, {num1, num2}});
                // if top is greater; pop it & push the smaller sum
                else if(sum < maxHeap.top().first)
                {
                    maxHeap.pop();
                    maxHeap.push({sum, {num1, num2}});
                }
                // if sum is greater i.e. 11 + 7 > then next sum will also be greater
                // no need to check those
                else
                    break;
            }
        }

        vector<vector<int>> pairs;

        while(!maxHeap.empty())
        {
            int num1 = maxHeap.top().second.first;
            int num2 = maxHeap.top().second.second;
            pairs.push_back({num1, num2});
            maxHeap.pop();
        }
        return pairs;

    }
};