using namespace std;

#include <iostream>


int trisum_series(int n){
    // base case
    if(n == 0 || n == 1 || n == 2){
        return n+1;
    }
    
    return trisum_series(n-1) + trisum_series(n-2) + trisum_series(n-3);
}


int main(){
    // n starts from 0, so it returns n + 1 element
    cout<<trisum_series(4) << endl; // 1, 2, 3, 6, 11
}