/*
Problem 4: Kth Largest Element
●  Difficulty: Medium	
●  Estimated Time: 30 minutes
●  Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Problem4 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort array in descending order
        sort(nums.begin(), nums.end(), greater<int>());

        // return kth largest element
        return nums[k-1];
    }
};