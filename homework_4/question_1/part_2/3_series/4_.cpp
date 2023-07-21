using namespace std;

#include <iostream>
#include<cmath>


int series_4(int n){
    // base case
    if(n == 0){
        return 1;
    }
    
    return pow(3, n) + series_4(n-1);
}


int main(){
    // return the sum of n+1 elements using this series 1+3+9+27+81+...+3^N
    // here n starts from 0
    cout << series_4(5) << endl; // 1 + 3 + 9 + 27 + 81 + 243 = 364
}