using namespace std;

#include <iostream>


int fibonacci_series(int n){
    // base case
    if(n == 0 || n == 1){
        return n;
    }
    
    return fibonacci_series(n-1) + fibonacci_series(n-2);
}


int main(){
    // returns nth fibonacci number; n starts from 1
    cout << fibonacci_series(4) << endl; // 1, 1, 2, 3
    cout << fibonacci_series(7) << endl; // 1, 1, 2, 3, 5, 8, 13
}

/*
Time Complexity = O(2^n)
Space Complexity = O(n)
*/
