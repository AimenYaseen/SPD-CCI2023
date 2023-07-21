/*
Robot Path Finding from Point A to B: 
1d Grid: 
A robot stands at point A and needs to go to point B. 
Points A and B are n units apart. Each unit is defined 
by an intermediate point (there are n-1 intermediate points). 
The robot can make either a 1 unit or a 2 unit jump at a time. 
In how many different ways can the robot get from point A to point B? 
Write a program to compute this quantity.
*/

using namespace std;

#include <iostream>
#include <vector>


// using memization approach
long long path_finding_1d(int n, vector<int>& possibilities)
{
    if(possibilities[n] != -1)
    {
        return possibilities[n];
    }

    return path_finding_1d(n-1, possibilities) + path_finding_1d(n-2, possibilities);
}


long long path_finding_1d(int a, int b){
    if(a > b || a <= 0 || b <= 0)
    {
        cout << "A point should be less than B OR A and B should be > 0" << endl;
        return -1;
    }

    int n;

    if (a != b)
    {
        n = b - a; // if a is not 0 || a != b
    }
    else
    {
        n = b;
    }
    
    vector<int> possibilities(n, {-1});
    possibilities[0] = 1; // F0 should be 1 because if A and B are equal then only one jump is required.
    possibilities[1] = 1;

    return path_finding_1d(n-1, possibilities);
}


int main(){
    // Case 0: a = 0 & b = 1
    cout << "a = 0 & b = 1 : " << path_finding_1d(0, 1) << endl; // Error a or b can't be zero

    // Case 1: a = b = 1
    cout << "a = 1 & b = 1 : " << path_finding_1d(1, 1) << endl; // 1

    // Case 2: a = 1 & b = 2
    cout << "a = 1 & b = 2 : " << path_finding_1d(1, 1) << endl; // 1

    // Case 3: a = 7 & b = 15
    cout << "a = 7 & b = 15 : " << path_finding_1d(7, 15) << endl; // 21

    // Case 4: a = 3 & b = 2
    cout << "a = 3 & b = 2 : " << path_finding_1d(3, 2) << endl; // Error: a should be less than b

}