using namespace std;

#include <iostream>
#include<cmath>


int P(int n, int r) {
    if (r == 0)
        return 1;
    
    return n * P(n-1, r-1);
}



int main(){
    // return the permutation using this formula N * P(N-1, R-1)
    cout << P(3, 3) << endl;  // it will return 6
}