/*
Problem 7: Find the difference
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: https://leetcode.com/problems/find-the-difference
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Problem7 {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> S;
        
        // store the count of characters of t string in hashmap
        for(char c: t){
            S[c]++;
        }

        // decrement the count of characters if it exists in string s
        for(char c: s){
            if(S[c] > 0){
                S[c]--;
            }
        }
        
        // find and return the character which has count > 0
        for(char c: t){
            if(S[c] > 0){
                return c;
            }
        }
        return ' ';
    }
};
