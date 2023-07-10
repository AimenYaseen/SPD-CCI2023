/*
Problem 7: Reverse Integer
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: https://leetcode.com/problems/reverse-integer/
*/

#include <iostream>

using namespace std;

class Problem7 {
public:
    int reverse(int x) {
        int MAX_INT = 2147483647; // 2^31 - 1
        int MIN_INT = -2147483648; // -2^31

        int upper_bound = MAX_INT / 10; // 214748364
        int lower_bound = MIN_INT / 10; // -214748364
        int last_u_digit = MAX_INT % 10; // 7
        int last_l_digit = MIN_INT % 10; // -8

        int result = 0;

        while(x){ // 321, 32, 3
            int digit = x % 10;  // 1, 2, 3
            x = x / 10; // 32, 3, 0

            // compare the result with upper_bound
            // if result > upper_bound => any new digit append at its end will make the result greater
            // if result = upper_bound => and digit to be added > MAX_INT last digit then it will exceeds the limit
            // same for lower_limit
            if((result >  upper_bound) || (result == upper_bound &&
            digit >= last_u_digit)){
                return 0;
            } else if((result <  lower_bound) || (result == lower_bound &&
            digit <= last_l_digit)){
                return 0;
            }

            result = (result * 10) + digit;  // 1, (1*10)+2= 12, (12*10)+3=123
        }
        return result;
    }
};


// Time Complexity = O(log x)
// Space Complexity = O(1)

int main(){
    Problem7 problem_7;

    // Case 1: leetcode output should be 91
    int return_value = problem_7.reverse(19);
    cout<< "input '19' \noutput '" << return_value << "' \n";

    // Case 2: loveleetcode output should be 123
    return_value = problem_7.reverse(321);
    cout<< "input: '321' \noutput: '" << return_value << "' \n";

    // Case 3: aabb output shiuld be 21
    return_value = problem_7.reverse(120);
    cout<< "input: '120' \noutput: '" << return_value << "' \n";
}