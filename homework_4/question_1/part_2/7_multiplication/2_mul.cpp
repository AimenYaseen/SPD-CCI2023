using namespace std;

#include <iostream>


int mulRec(int y, int sum, int c)
{
    if(c > y) return sum;
    return mulRec(y-c, sum+sum, c+c);
}


int multiplication(int x, int y)
{
    return x + mulRec(y-1, x, 1);
}


// int multiplication(int x, int y)
// {
//     if (y == 0)
//         return 0;
        
//     if (y % 2 == 0)
//     {
//         int temp = multiplication(x, y / 2);
//         return temp + temp;
//     }
//     else
//         return x + multiplication(x, y - 1);
// }

int main()
{
    cout << multiplication(2, 3) << endl; // 6
    cout << multiplication(4, 3) << endl; // 12
}

/*
Time Complexity = O(logy)
Space Complexity = O(logy)
*/
