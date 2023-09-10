using namespace std;

#include <iostream>
#include<cmath>


int series_5(int n) {
    if (n == 1 || n == 0) {
        return n;
    } else {
        return 3 * series_5(n - 1) + (n-1) / 9 + (n-1) / 3 + (n-1);
    }
}



int main(){
    // return the sum of n elements using this series 1+3+9+27+81+...+N/9+N/3+N
    // here n starts from 1
    cout << series_5(2) << endl;  // it will return 4
}