/*
Problem 2b: Remove Duplicate Numbers
●  Difficulty: Medium
●  Estimated Time: 30 minutes
●  Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array
*/

#include <iostream>
#include <vector>

using namespace std;


class Problem2b {
public:
    int removeDuplicates(vector<int>& nums) {
        int t = 1; // track unique numbers and their count

        for(int i=1; i<nums.size(); i++){
            // if two adjacent numbers are different
            if(nums[i - 1] != nums[i]){
                // swap the unique one to the start of array
                nums[t] = nums[i];
                t++;
            }
        }

        return t;
    }
};