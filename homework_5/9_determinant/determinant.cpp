/*
Finding Determinant of matrix
*/
using namespace std;

#include <iostream>
#include <vector>
#include <cmath>


vector<vector<double>> getSubMatrix(vector<vector<double>> matrix, int col)
{
    int n = matrix.size();

    vector<vector<double>> sub_matrix;

    // always starts from 1 because we ignore the 0 row
    for (int i = 1; i < n; i++) 
    {
        vector<double> sub_row;
        for (int j = 0; j < n; j++) 
        {
            if (j != col)
                sub_row.push_back(matrix[i][j]);
        }
        sub_matrix.push_back(sub_row);
    }

    return sub_matrix;
}

// Function to calculate the determinant of a submatrix
double RecDeterminant(const vector<vector<double>>& matrix) {
    int n = matrix.size();

    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];


    int sign = 1;
    double det = 0;

    // row will always be zero
    for (int col = 0; col < n; col++) {
        // here col number will be the column which we want to ignore
        auto sub_matrix = getSubMatrix(matrix, col);
        
        det += sign * matrix[0][col] * RecDeterminant(sub_matrix);
        sign *= -1;
    }
    return det;
}

int main() {
    vector<vector<double>> A = {
        {1, 2, 3, 4},
        {1, 2, 5, 1},
        {1, 5, 6, 3},
        {1, 1, 2, 1}
    };

    double det = RecDeterminant(A);

    cout << "Determinant of matrix: " << det << endl;

    return 0;
}
