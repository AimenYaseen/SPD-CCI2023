using namespace std;

#include <string>
#include <unordered_map>


class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int value = 0;
        int n = s.size();

        for(int i=0; i<n; i++)
        {
            // check if prev letter is smaller 
            // this case is only true for IV, IX, XL, XC, CD, CM
            if(i+1 < n && m[s[i]] < m[s[i+1]])
                // substract it from value
                value -= m[s[i]];
            else
                value += m[s[i]];
        }

        return value;
    }
};