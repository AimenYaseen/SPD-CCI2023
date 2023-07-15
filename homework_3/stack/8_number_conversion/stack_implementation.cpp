using namespace std;

#include <stack>
#include <iostream>


long long int decimalToBinary(int n){
    stack<int> s;

    while(n != 0){
        int digit = n % 2;
        s.push(digit);
        n /= 2;
    }

    long long int result = 0;
    while(!s.empty()){
        int digit = s.top();
        s.pop();
        result = (result * 10) + digit;
    }

    return result;
}


int main(){
    // Case 1: input => 5; output => 101
    long long int result = decimalToBinary(5);
    cout << "Input: 5 => output: " << result << endl;

    // Case 2: input => 16; output => 10000
    result = decimalToBinary(16);
    cout << "Input: 16 => output: " << result << endl;

    // Case 3: input => 127; output => 1111111
    result = decimalToBinary(127);
    cout << "Input: 127 => output: " << result << endl;
}