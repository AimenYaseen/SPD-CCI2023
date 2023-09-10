using namespace std;

#include <iostream>


int series_1(int n){
    // base case
    if(n == 0){
        return 0;
    }
    
    return n + series_1(n-1);
}


int main(){
    // return the sum of n elements using this series 1+2+3+4+...+N
    cout<<series_1(4) << endl; // 1 + 2 + 3 + 4 = 10
}