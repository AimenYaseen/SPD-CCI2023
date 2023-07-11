/*
Problem 3: Find Array Intersection
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: https://leetcode.com/problems/intersection-of-two-arrays-ii
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Problem3 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> common_elements;
        unordered_map<int, int> numbers_count;

        // store the count of nums1 numbers
        for(int num: nums1){
            numbers_count[num]++;
        }

        // traverse through nums2
        for(int num: nums2){
            /*
            if current number count > 0 in hashmap
            them add it in vector and decrement the count
            */
            if(numbers_count[num] > 0){
                common_elements.push_back(num);
                numbers_count[num]--;
            }
        }

        return common_elements;
    }
};