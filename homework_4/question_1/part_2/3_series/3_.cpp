using namespace std;

#include <iostream>
#include<cmath>


int series_3(int n){
    // base case
    if(n == 0){
        return 1;
    }
    
    return pow(2, n) + series_3(n-1);
}


int main(){
    // return the sum of n+1 elements using this series 1+2+4+8+16+...+2N 
    // here n starts from 0
    cout << series_3(5) << endl; // 1 + 2 + 4 + 8 + 16 + 32 = 63
}