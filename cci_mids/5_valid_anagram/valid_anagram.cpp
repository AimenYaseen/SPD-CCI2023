#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


bool isAnagram(string s, string t)
{
    if(s.size() != t.size()) return false;

    unordered_map<char, int> count_map;

    for(char c: s)
    {
        if(isalpha(c)) 
            c = tolower(c);

        count_map[c]++;
    }

    for(char c: t)
    {
        if(isalpha(c)) 
            c = tolower(c);

        if(count_map.count(c) == 0) return false;
        count_map[c]--;
    }

    for(auto const &pair: count_map)
    {
        if(pair.second != 0) return false;
    }

    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cout << isAnagram("anagram", "NaGaRam");
    cout << isAnagram("Test12$", "12$tesT");
    cout << isAnagram("/\/\/B", "\/\/ba");
    return 0;
}