/*
Fibonacci Dynamic Programming  (Top Down Recursive and Memoization Approaches)
*/

using namespace std;

#include <iostream>
#include <vector>


long long Fib(int n, vector<int>& Vs){
    if(Vs[n] != -1)
    {
        return Vs[n];
    }

    return Fib(n-1, Vs) + Fib(n-2, Vs);
}

long long Fib(int n)
{
    if(n <= 0)
    {
        cout << "n must start from 1" << endl ;
        return -1;
    }

    vector<int> Vs(n, {-1});
    // this fibonacci starts from 0
    Vs[0] = 0;  // F0
    Vs[1] = 1;  // F1

    return Fib(n-1, Vs);
}


int main(){
    cout << "0th Fibonacci: " << Fib(0) << endl; // -1
    cout << "1st Fibonacci: " << Fib(1) << endl; // 0
    cout << "5th Fibonacci: " << Fib(5) << endl; // 0 1 1 2 3
    cout << "10th Fibonacci: " << Fib(10) << endl; // 0 1 1 2 3 5 8 13 21 34
}