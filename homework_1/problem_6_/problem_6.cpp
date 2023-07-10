/*
Problem 6: Happy Numbers
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: https://leetcode.com/problems/happy-number/
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Problem6 {
private:
    int sumOfSquares(int n){
        int sum = 0;
        while(n){ // n = 19
            int digit = n % 10; // digit = 9
            sum += (digit * digit); // sum = 81
            n = n / 10; // n = 1
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;

        while(set.count(n) == 0){
            set.insert(n);
            n = sumOfSquares(n);

            if(n == 1){
                return true;
            }
        }
        return false;
    }
};


// Time Complexity = O(n)
// Space Complexity = O(n)

int main(){
    Problem6 problem_6;

    // Case 1: leetcode output should be true
    bool return_value = problem_6.isHappy(19);
    cout<< "input '19' \noutput '" << return_value << "' \n";

    // Case 2: loveleetcode output should be false
    return_value = problem_6.isHappy(2);
    cout<< "input: '2' \noutput: '" << return_value << "' \n";

    // Case 3: aabb output shiuld be true
    return_value = problem_6.isHappy(7);
    cout<< "input: '7' \noutput: '" << return_value << "' \n";
}
