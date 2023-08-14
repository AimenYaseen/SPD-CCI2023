/*
Some of the interior points in the grid are broken, 
so that the robot cannot stop at them. Consider these as dead points. 
How will the recursion above be modified such that, if a path exists 
from A to B, the robot must take it.
*/

#include <iostream>
#include <vector>

using namespace std;

int path_finding_2d(int row, int col, int n, vector<vector<bool>>& broken)
{
    if (row == n - 1 || col == 0)
    {
        return 1;
    }

    // Check if the current cell is a broken interior point
    if (broken[row][col])
    {
        return 0;
    }

    return path_finding_2d(row, col - 1, n, broken) + path_finding_2d(row + 1, col, n, broken);
}

int path_finding_2d(int grid_size, vector<vector<bool>>& broken)
{
    int row = 0, column = grid_size - 1; // destination i.e. B's location (0, 3)
    return path_finding_2d(row, column, grid_size, broken);
}

int main() {
    int grid_size = 4;
    
    // Define broken interior points
    vector<vector<bool>> broken(grid_size, vector<bool>(grid_size, false));
    broken[1][1] = true;
    broken[2][2] = true;

    cout << "From a = (" << grid_size - 1 << ", 0) to b = (0, " << grid_size - 1 << "), ways to reach there = " << path_finding_2d(grid_size, broken) << endl;

    return 0;
}
