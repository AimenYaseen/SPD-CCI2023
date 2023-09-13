using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
    bool search(vector<vector<int>>& matrix, int target, int r, int c, int rows)
    {
        if(r > rows || c < 0)
            return false;

        if(target == matrix[r][c])
            return true;
        else if(target > matrix[r][c])
            return search(matrix, target, r+1, c, rows);
        else
            return search(matrix, target, r, c-1, rows);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size() - 1;
        int c = matrix[0].size() - 1;

        return search(matrix, target, 0, c, r);
    }
};

