using namespace std;

#include <iostream>
#include<cmath>


int series_3(int n){
    // base case
    if(n == 1){
        return 1;
    }
    
    return pow(2, n-1) + series_3(n-1);
}


int main(){
    // return the sum of n elements using this series 1+2+4+8+16+...+2N 
    // here n starts from 1
    cout << series_3(5) << endl; // 1 + 2 + 4 + 8 + 16 = 31
}