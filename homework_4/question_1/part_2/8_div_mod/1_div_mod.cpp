using namespace std;

#include <iostream>


pair<int, int> divModRec(int A, int B, int q)
{
    // base case
    if(A < B)
        return {q, A};
    
    return divModRec(A-B, B, q+1);
}

pair<int, int> divMod(int A, int B)
{    
    return divModRec(A, B, 0);
}

int main()
{
    auto result = divMod(3, 2);
    cout << "Quotient: " <<  result.first << " Remainder: " << result.second << endl; // 1, 1
    
    result = divMod(5, 2);
    cout << "Quotient: " <<  result.first << " Remainder: " << result.second << endl; // 2, 1
}

/*
Time Complexity = O(y)
Space Complexity = O(y)
*/
