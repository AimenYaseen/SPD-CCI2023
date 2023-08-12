using namespace std;

#include <iostream>
#include<cmath>


int C(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    
    return C(n-1, r-1) + C(n-1, r);
}



int main(){
    // return the combination using this formula C(n-1, r-1) + C(n-1, r)
    cout << C(5, 2) << endl;  // it will return 10
}