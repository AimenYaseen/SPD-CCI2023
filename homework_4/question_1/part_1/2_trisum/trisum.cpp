using namespace std;

#include <iostream>


int trisum_series(int n){

    if(n == 0 || n == 1 || n == 2 || n == 3){
        return n;
    }
    
    return trisum_series(n-1) + trisum_series(n-2) + trisum_series(n-3);
}


int main(){
    // returns nth trisum; n starts from 1
    cout<<trisum_series(4) << endl; // 1, 2, 3, 6
}