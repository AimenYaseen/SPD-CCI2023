using namespace std;

#include <vector>
#include <string>
#include <limits.h>
#include <unordered_map>


class Solution {
    typedef pair<int, int> pair;
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(char c: t)
            m[c]++;
        
        int i = 0;
        int j = 0;
        
        // # of chars in t that must be in s
        int counter = t.size();
        
        int minStart = 0;
        int minLength = INT_MAX;
        
        while (j < s.size()) 
        {
            // if char in s exists in t, decrease
            if (m[s[j]] > 0)
                counter--;

            // if char doesn't exist in t, will be -'ve
            m[s[j]]--;
            // move j to find valid window
            j++;
            
            // when window found, move i to find smaller
            while (counter == 0) 
            {
                if (j - i < minLength) 
                {
                    minStart = i;
                    minLength = j - i;
                }
                
                m[s[i]]++;
                // when char exists in t, increase
                if (m[s[i]] > 0)
                    counter++;
                
                i++;
            }
        }
        
        if (minLength != INT_MAX)
            return s.substr(minStart, minLength);
        return "";
    }
};