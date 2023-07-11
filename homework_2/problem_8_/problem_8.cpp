/*
Problem 8: Sort Characters By Frequency
●  Difficulty: Medium
●  Estimated Time: 1 hour
●  Problem Link: https://leetcode.com/problems/sort-characters-by-frequency
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Problem8 {
public:
    string frequencySort(string s) {
        unordered_map<int, int> sCount;

        for(char c : s){
            sCount[c]++;
        }

        // custom sort logic
        auto sort_order = [&](int first, int second){
            if(sCount[first] == sCount[second]){
                return first < second;
            }
            return sCount[first] > sCount[second];
        };

        sort(s.begin(), s.end(), sort_order);
        return s;
    }
};