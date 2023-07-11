/*
Problem 6: Two String are Equivalent
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Problem6 {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";

        // concatenate strings of word1 array
        for(string s: word1){
            s1 += s;
        }

        // concatenate strings of word2 array
        for(string s: word2){
            s2 += s;
        }

        // compare strings and return bool result
        return s1 == s2;
    }
};