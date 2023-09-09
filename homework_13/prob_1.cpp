using namespace std;

#include <vector>
#include <iostream>
#include <limits.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;

        for(int num: nums)
        {
            curSum = curSum + num;

            if(maxSum < curSum)
                maxSum = curSum;

            if(curSum < 0)
                curSum = 0;
        }
        return maxSum;
    }
};