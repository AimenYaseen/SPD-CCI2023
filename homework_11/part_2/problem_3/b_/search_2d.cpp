using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
    bool search(vector<vector<int>>& matrix, int target, int r, int c, int rows, int cols)
    {
        if(r > rows)
            return false;

        if(target == matrix[r][c])
            return true;
        else if(r+1 <= rows && target >= matrix[r+1][c])
            return search(matrix, target, r+1, c, rows, cols);
        else
        {
            for(int i = 0; i <= cols; i++)
            {
                if(target == matrix[r][i])
                    return true;
            }
            return false;
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size() - 1;
        int c = matrix[0].size() - 1;

        return search(matrix, target, 0, 0, r, c);
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1,3,5,7}, 
        {10,11,16,20},
        {23,30,34,60}
    };

    vector<vector<int>> m1 = {{1}, {3}};

    Solution sol;
    sol.searchMatrix(m1, 3);
}