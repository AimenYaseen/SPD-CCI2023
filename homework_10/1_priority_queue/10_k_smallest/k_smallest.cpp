using namespace std;

#include <vector>
#include <queue>


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto row: matrix)
            for(auto col: row)
                minHeap.push(col);

        while(!minHeap.empty() && k-1)
        {
            minHeap.pop();
            k--;
        }

        return minHeap.top();
    }
};
