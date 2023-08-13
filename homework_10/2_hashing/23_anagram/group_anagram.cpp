using namespace std;

#include <string>
#include <unordered_map>
#include <vector>


class Solution {
public:
    string getKey(string str) {
        vector<int> count(26, 0);

        for(char c: str)
            count[c - 'a']++;
        
        string key = "";
        for (int c: count)
            key.append(to_string(c) + ' ');
        
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        if(n==0 || n==1) return {strs};

        unordered_map<string, vector<string>> a_group;

        for(string s: strs)
        {
            string key = getKey(s);
            a_group[key].push_back(s);
        }

        vector<vector<string>> result;

        for(auto pair: a_group)
            result.push_back(pair.second);
        
        return result;
    }
};