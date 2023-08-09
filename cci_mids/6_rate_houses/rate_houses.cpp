#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int rate_houses(vector<int> arr)
{
    int points = 1;
    int last_point = 1;

    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i] > arr[i-1])
            last_point++;
        else
            last_point = 1;
        points += last_point;
    }
    return points;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> V({1, 2, 3});
    vector<int> V1({2, 5, 5});
    vector<int> V2({3, 2, 5, 5, 6});

    cout << rate_houses(V) << endl;
    cout << rate_houses(V1) << endl;
    cout << rate_houses(V2) << endl;
    return 0;
}