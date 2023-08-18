using namespace std;

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
    struct Compare
    {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) const
        {
            return a.second < b.second;
        }
    };
public:
    string frequencySort(string s) {
        unordered_map<char, int> sCount;

        for(char c : s){
            sCount[c]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> freq_char;

        for(auto pair: sCount)
            freq_char.push(pair);


        string result;
        while(!freq_char.empty())
        {
            char c = freq_char.top().first;
            int count = freq_char.top().second;
            freq_char.pop();

            for(int i=1; i <= count; i++)
                result += c;
        }

        return result;
    }
};