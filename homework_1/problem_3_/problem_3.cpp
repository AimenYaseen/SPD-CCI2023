/*
Problem 3: Find the index of the First Occurance in a String
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: findIndex
*/

#include<string>
#include <iostream>

using namespace std;

class Problem3 {
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.size();

        // if needle is empty then it should be exist at index 0
        if(needle_size == 0){
            return 0;
        } else if(needle_size > haystack.size()){ // if needle is greater than haystack
            return -1;
        }

        for(int i=0; i<=(haystack.size() - needle_size); i++){
            // if first character doesn't match 
            if(haystack[i] != needle[0]){
                continue;
            }
            for(int j=0; j<needle_size; j++){
                if(haystack[i + j] != needle[j]){
                    break;
                } 
                if(j == (needle_size - 1)) {
                    return i;
                }
            }
        }
        return -1;
    }
};

// Time Complexity = O(n * m)
// Space Complexity = O(1)

int main(){
    Problem3 problem_3;

    // Case 1: leetcode output should be 0
    int return_value = problem_3.strStr("sadbutsad", "sad");
    cout<< "input \'sadbutsad, sad' \noutput \'" << return_value << "\' \n";

    // Case 2: loveleetcode output shiuld be -1
    return_value = problem_3.strStr("leetcode", "leeto");
    cout<< "input: \'leetcode, leeto' \noutput: \'" << return_value << "\' \n";

    // Case 3: aabb output shiuld be 2
    return_value = problem_3.strStr("hello", "ll");
    cout<< "input: \'hello, ll' \noutput: \'" << return_value << "\' \n";
}