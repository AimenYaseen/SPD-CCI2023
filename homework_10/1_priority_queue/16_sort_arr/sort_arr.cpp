using namespace std;

#include <queue>
#include <vector>


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto num: nums)
            minHeap.push(num);

        vector<int> sorted_arr;

        while(!minHeap.empty())
        {
            sorted_arr.push_back(minHeap.top());
            minHeap.pop();
        }

        return sorted_arr;
    }
};