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


class Problem1 {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charMap;

        for(int i=0; i<s.size(); i++){
            char c = s[i];
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

// used hashtable
// Time Complexity = O(n)
// Space Complexity = O(n)

int main(){
    Problem1 problem_1;

    // Case 1: leetcode output should be 0
    int return_value = problem_1.firstUniqChar("leetcode");
    cout<< "input \'leetcode' \noutput \'" << return_value << "\' \n";

    // Case 2: loveleetcode output shiuld be 2
    return_value = problem_1.firstUniqChar("loveleetcode");
    cout<< "input: \'loveleetcode' \noutput: \'" << return_value << "\' \n";

    // Case 3: aabb output shiuld be -1
    return_value = problem_1.firstUniqChar("aabb");
    cout<< "input: \'aabb' \noutput: \'" << return_value << "\' \n";
}
