using namespace std;

#include <string>
#include <unordered_set>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hash set
        unordered_set<char> substring;

        int maxCount = 0;
        int n = s.size();
        // two pointer or sliding window approach
        int slow = 0, fast = 0;

        while(fast < n)
        {
            // if char is not in set, insert it and inc fast
            if(substring.find(s[fast]) == substring.end())
            {
                substring.insert(s[fast]);
                fast++;
                // calculate the max string count
                // fast - slow current unique string
                maxCount = max(maxCount, fast - slow);
            }
            else
            {
                // if it is already present; pop the elements until we make current unique
                substring.erase(s[slow]);
                // shift the window
                slow++;
            }
        }

        return maxCount;
    }
};