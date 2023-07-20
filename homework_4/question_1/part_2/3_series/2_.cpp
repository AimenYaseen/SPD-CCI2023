using namespace std;

#include <iostream>


int series_2(int n){
    // base case
    if(n == 1){
        return 1;
    }
    
    return n + series_2(n-2);
}


int series_22(int n, int i){
    // base case
    if(i == n){
        return n;
    }
    
    return i + series_22(n, i+2);
}


int main(){
    // return the sum of n elements using this series 1+3+5+7+....+N 
    // (where N must be odd) 
    cout << series_2(5) << endl; // 1 + 3 + 5 = 9

    cout << series_22(3, 1) << endl; // 1 + 3 = 4
}