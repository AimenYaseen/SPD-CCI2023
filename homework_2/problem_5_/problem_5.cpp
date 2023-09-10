/*
Problem 5: Squares of Sorted Array
●  Difficulty: Easy-Medium
●  Estimated Time: 30 minutes
●  Problem Link: https://leetcode.com/problems/squares-of-a-sorted-array
*/

#include <iostream>
#include <vector>

using namespace std;


class Problem5 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sortedVector(nums.size(), 0);

        // initiale start and end pointer
        int start=0, end=nums.size()-1;
        int index=nums.size()-1; // sortedVector pointer

        
        while(start<=end){
            // compute squares
            int start_square = nums[start]*nums[start];
            int end_square = nums[end]*nums[end];

            // start_square is greater than end_square put it at sortedVector end position
            // otherwise put end_square
            // update the indexes accordingly
            if(start_square > end_square){
                sortedVector[index] = start_square;
                start++;
                index--;
            } else {
                sortedVector[index] = end_square;
                end--;
                index--;
            }
        }

        return sortedVector;
    }
};