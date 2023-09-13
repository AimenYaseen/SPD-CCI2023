using namespace std;

#include <string>
#include <unordered_set>
#include <vector>


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;
        
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (zeroRows.count(i) || zeroCols.count(j))
                    matrix[i][j] = 0;
            }
        }
        
    }
};
