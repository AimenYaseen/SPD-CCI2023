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
    // n starts from 0, so it returns n + 1 element
    cout << fibonacci_series(4) << endl; // 0, 1, 1, 2, 3
    cout << fibonacci_series(7) << endl; // 0, 1, 1, 2, 3, 5, 8, 13
}