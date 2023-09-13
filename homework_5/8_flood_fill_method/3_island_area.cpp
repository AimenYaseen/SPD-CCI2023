using namespace std;

#include<vector>


class Solution {
public:
    void AreaOfIsland(vector<vector<int>>& grid, int rows, int cols, int r, int c, int &area)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return;

        area++;
        // mark as visited
        grid[r][c] = 0;

        AreaOfIsland(grid, rows, cols, r + 1, c, area);
        AreaOfIsland(grid, rows, cols, r - 1, c, area);
        AreaOfIsland(grid, rows, cols, r, c + 1, area);
        AreaOfIsland(grid, rows, cols, r, c - 1, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int max_area = 0;

        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if(grid[r][c] == 0) continue;
                int area = 0;
                AreaOfIsland(grid, rows, cols, r, c, area);
                max_area = max(area, max_area);
            }
        }

        return max_area;
    }
};
