/*
Problem 10: Set Matrix Zeros
●  Difficulty: Medium
●  Estimated Time: 60 minutes
●  Problem Link: https://leetcode.com/problems/set-matrix-zeroes
*/

#include <iostream>
#include <vector>

using namespace std;


class Problem10 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> rowVector, colVector;

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(matrix[r][c] == 0){
                    rowVector.push_back(r);
                    colVector.push_back(c);
                }
            }
        }

        for(int r=0; r<rowVector.size(); r++){
            int ri = rowVector[r];
            for(int c=0; c<col; c++){
                matrix[ri][c] = 0;
            }
        }

        for(int c=0; c<colVector.size(); c++){
            int ci = colVector[c];
            for(int r=0; r<row; r++){
                matrix[r][ci] = 0;
            }
        }
        
    }
};