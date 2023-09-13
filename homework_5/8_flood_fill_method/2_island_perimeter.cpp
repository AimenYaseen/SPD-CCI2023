using namespace std;

#include<vector>


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid, int r, int c, int rows, int cols, int &perimeter)
    {
        // base case; if there is water or boundary reaches
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) 
            return 1;

        if(grid[r][c] == -1) return 0;

        grid[r][c] = -1;

        perimeter = islandPerimeter(grid, r+1, c, rows, cols, perimeter) +
                    islandPerimeter(grid, r-1, c, rows, cols, perimeter) +
                    islandPerimeter(grid, r, c+1, rows, cols, perimeter) +
                    islandPerimeter(grid, r, c-1, rows, cols, perimeter);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if(grid[r][c] == 1)
                    return islandPerimeter(grid, r, c, rows, cols, perimeter);
            }
        }

        return perimeter;
    }
};
