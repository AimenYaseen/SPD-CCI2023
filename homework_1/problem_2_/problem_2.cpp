/*
Problem 2: Valid Anagram
●  Difficulty: Easy	
●  Estimated Time: 30 minutes
●  Problem Link: validAnagram 
*/

#include<string>
#include <iostream>
#include<unordered_map>

using namespace std;

class Problem2 {
public:
    bool isAnagram(string s, string t) {
        // only equal length of strings can be an anagram
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for(int i=0; i<s.size(); i++){
            sMap[s[i]]++;
            tMap[t[i]]++;
        }   
        return sMap == tMap;
    }
};


// Time Complexity = O(n)
// Space Complexity = O(n)

int main(){
    Problem2 problem_2;

    // Case 1: leetcode output should be True
    int return_value = problem_2.isAnagram("anagram", "nagaram");
    cout<< "input \'anagram, nagaram' \noutput \'" << return_value << "\' \n";

    // Case 2: loveleetcode output shiuld be False
    return_value = problem_2.isAnagram("rat", "car");
    cout<< "input: \'rat, car' \noutput: \'" << return_value << "\' \n";

    // Case 3: aabb output shiuld be False
    return_value = problem_2.isAnagram("aabb", "bba");
    cout<< "input: \'aabb, bba' \noutput: \'" << return_value << "\' \n";
}
