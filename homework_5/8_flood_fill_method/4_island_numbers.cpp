using namespace std;

#include<vector>


class Solution {
public:
    void visitIsland(vector<vector<char>>& grid, int rows, int cols, int r, int c)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        visitIsland(grid, rows, cols, r + 1, c);
        visitIsland(grid, rows, cols, r - 1, c);
        visitIsland(grid, rows, cols, r, c + 1);
        visitIsland(grid, rows, cols, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int result = 0;

        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if(grid[r][c] == '0') continue;
                visitIsland(grid, rows, cols, r, c);
                result++;
            }
        }

        return result;
    }
};