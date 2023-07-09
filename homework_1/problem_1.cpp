/* 
Problem 1: First Unique Character in a String
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: First Unique Character in a String 
*/
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>


class SecondAttempt {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charMap;

        for(char c: s){
            charMap[c]++;
        }

        for(int i=0; i<s.size(); i++){
            if(charMap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

// used hashtables 
// Time Complexity = O(n)
// Space Complexity = O(n)

int main(){
    SecondAttempt second_attempt;

    // Case 1: leetcode output should be 0
    int return_value = second_attempt.firstUniqChar("leetcode");
    cout<< "input \'leetcode' \noutput \'" << return_value << "\' \n";

    // Case 2: loveleetcode output shiuld be 2
    return_value = second_attempt.firstUniqChar("loveleetcode");
    cout<< "input: \'loveleetcode' \noutput: \'" << return_value << "\' \n";

    // Case 3: aabb output shiuld be -1
    return_value = second_attempt.firstUniqChar("aabb");
    cout<< "input: \'aabb' \noutput: \'" << return_value << "\' \n";
}
