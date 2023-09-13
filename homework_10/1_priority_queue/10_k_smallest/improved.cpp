using namespace std;

#include <vector>
#include <queue>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // create max heap
        priority_queue<int> maxHeap;

        for(auto row: matrix)
        {   
            for(auto col: row)
            {    
                maxHeap.push(col);
                // if maxHeap size > k; pop the max 
                if(maxHeap.size() > k)
                    maxHeap.pop();
            }
        }
        // at this point; maxHeap contains k values
        // and the top one contains the kth smallest
        return maxHeap.top();
    }
};