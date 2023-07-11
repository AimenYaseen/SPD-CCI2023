/*
Problem 9: Rotate Image
●  Difficulty: Medium
●  Estimated Time: 60 minutes
●  Problem Link: https://leetcode.com/problems/rotate-image
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Problem9 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        // take transponse
        for(int r=0; r<row; r++){
            for(int c=0; c<r; c++){
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        // reverse the rows
        for(int r=0; r<row; r++){
            reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};