using namespace std;

#include <iostream>


int multiplication(int x, int y)
{
    // base case
    if(y == 0)
        return 0;
    
    return x + multiplication(x, y-1);
}


int main()
{
    cout << multiplication(2, 3) << endl; // 6
    cout << multiplication(4, 3) << endl; // 12
}

/*
Time Complexity = O(y)
Space Complexity = O(y)
*/
