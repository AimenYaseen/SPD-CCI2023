using namespace std;

#include <iostream>
#include<cmath>


int series_4(int n){
    // base case
    if(n == 1){
        return 1;
    }
    
    return pow(3, n-1) + series_4(n-1);
}


int main(){
    // return the sum of n elements using this series 1+3+9+27+81+...+3^N
    // here n starts from 1
    cout << series_4(5) << endl; // 1 + 3 + 9 + 27 + 81 = 121
}