using namespace std;

#include <iostream>
#include<cmath>


int series_6(int n) {
    if (n == 1 || n == 0) {
        return n;
    } else {
        return 2 * series_6(n - 1) + (n-1) / 4 + (n-1) / 2 + (n-1);
    }
}



int main(){
    // return the sum of n elements using this series 1+2+4+8+16+...+ N/2+N
    // here n starts from 1
    cout << series_6(2) << endl;  // it will return 3
}