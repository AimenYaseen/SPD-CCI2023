/*
The robot now stands at the bottom left corner, A, of an n x n grid,
and needs to get to the top right right corner, B.
It can only make a 1 unit jump either upward or rightward. 
In how many different ways, can it now get from A to B.
*/

using namespace std;

#include <iostream>

int path_finding_2d(int row, int col, int n)
{
    if(row == n - 1 || col == 0)
    {
        return 1;
    }

    return path_finding_2d(row, col - 1, n) + path_finding_2d(row + 1, col, n);
}

int path_finding_2d(int grid_size)
{
    int row = 0, column = grid_size - 1; // destination i.e. B's location (0, 3)
    return path_finding_2d(row, column, grid_size);
}


int main(){
    // Case 1: grid size is 4
    cout << "From a = (3, 0) to b = (0, 3), ways to reach there = " << path_finding_2d(4) << endl;

    // a = (3, 0), b = (0, 3)
    // if a = 3 return 1; if c = 0 return 1;
}