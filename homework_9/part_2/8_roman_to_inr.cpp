using namespace std;

#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>


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
            {'M', 1000}
        };

        int value = 0;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(i+1 < n && m[s[i]] < m[s[i+1]])
                value -= m[s[i]];
            else
                value += m[s[i]];
        }

        return value;
    }
};