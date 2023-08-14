using namespace std;

#include <iostream>


int power(int x, int y, int m)
{
    // base case
    if(y == 0)
        return 1;
    
    return x * power(x, y-1, m) % m;
}


int main()
{
    cout << power(2, 2, 1) << endl; // (2^2 % 1 = 0)
    cout << power(4, 3, 5) << endl; // (4^3 % 5 = 4)
}

/*
Time Complexity = O(y)
Space Complexity = O(y)
*/
