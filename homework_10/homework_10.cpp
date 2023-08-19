using namespace std;

#include <queue>
#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

// ______________________________ PRIORITY QUEUE _________________________________________

/*
------------------------------------------------------------------------------------
Question # 01 - Max Product
------------------------------------------------------------------------------------
*/

class Qusetion1 {
public:
    int maxProduct(vector<int>& nums) {
        // create a max heap
        priority_queue<int, vector<int>> p_nums;

        for(int num: nums)
            p_nums.push(num);

        // get the 1st 2 maximum numbers
        int num1 = p_nums.top() - 1;
        p_nums.pop();
        int num2 = p_nums.top() - 1;

        return num1 * num2;
    }
};

/* 
------------------------------------------------------------------------------------
Question # 02 - Relative Ranks
------------------------------------------------------------------------------------
*/

class Question2 {
    struct Compare
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
        {
            return a.second < b.second;
        }
    };
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // create a max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> p_score;

        int n = score.size();
        for(int i = 0; i < n; i++)
            p_score.push({i, score[i]});

        vector<string> ranks(n, "");

        int i = 1;

        for(int i=1; i <= n; i++)
        {
            int index = p_score.top().first;
            p_score.pop();

            if( i == 1)
                ranks[index] = "Gold Medal";
            else if(i == 2)
                ranks[index] = "Silver Medal";
            else if(i == 3)
                ranks[index] = "Bronze Medal";
            else
                ranks[index] = to_string(i);
        }

        return ranks;
    }
};

/* 
------------------------------------------------------------------------------------
Question # 03 - K Closest Elements to X
------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find x in array
        // get the lower bound
        // if value is not present, it returns the value just greater than the target
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx;

        // if target is smaller than the arr first element
        // then the pivot is 0 index
        if(it == arr.begin())
            idx = 0;
        // if target is greater than the last element in arr 
        // then last index will be the pivot
        else if(it == arr.end())
            idx = arr.size() - 1;
        else
        {
            // if value = target or greater than target
            // find absolute difference
            // if current is less or equal then this is the index
            // otherwise previous will be the index
            int curDiff = abs(*it - x);
            int prevDiff = abs(*(it - 1) - x);
            idx = curDiff < prevDiff ? it - arr.begin() : (it - 1)  - arr.begin();
        }

        // assign l & r to pivot index
        int l = idx, r = idx;

        for (int i = 0; i < k - 1; ++i) 
        {
            // if l at index 0
            if (l == 0)
                ++r;
            else if (r == arr.size() - 1 || x - arr[l - 1] <= arr[r + 1] - x) 
                --l;
            else
                ++r;
        }

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);

    }
};

/* 
------------------------------------------------------------------------------------
Question # 07 - Sort Characters by Frequency
------------------------------------------------------------------------------------
*/

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

/* 
------------------------------------------------------------------------------------
Question # 10 - kth smallest element in matrix
------------------------------------------------------------------------------------
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // create max heap
        priority_queue<int> maxHeap;

        for(auto row: matrix)
        {   
            for(auto col: row)
            {    
                maxHeap.push(col);
                // if maxHeap size > k; pop the max 
                if(maxHeap.size() > k)
                    maxHeap.pop();
            }
        }
        // at this point; maxHeap contains k values
        // and the top one contains the kth smallest
        return maxHeap.top();
    }
};

/* 
------------------------------------------------------------------------------------
Question # 11 - kth smallest sum
------------------------------------------------------------------------------------
*/

class Solution {
    typedef pair<int, pair<int, int>> pr;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pr> maxHeap;

        for(auto num1: nums1)
        {
            for(auto num2: nums2)
            {
                int sum = num1 + num2;
                // push the first k pairs
                if(maxHeap.size() < k)
                    maxHeap.push({sum, {num1, num2}});
                // if top is greater; pop it & push the smaller sum
                else if(sum < maxHeap.top().first)
                {
                    maxHeap.pop();
                    maxHeap.push({sum, {num1, num2}});
                }
                // if sum is greater i.e. 11 + 7 > then next sum will also be greater
                // no need to check those
                else
                    break;
            }
        }

        vector<vector<int>> pairs;

        while(!maxHeap.empty())
        {
            int num1 = maxHeap.top().second.first;
            int num2 = maxHeap.top().second.second;
            pairs.push_back({num1, num2});
            maxHeap.pop();
        }
        return pairs;

    }
};

/* 
------------------------------------------------------------------------------------
Question # 12 - Design Twitter
------------------------------------------------------------------------------------
*/

class Twitter {
    // user_id -> time, tweet_id
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    // follower, followee
    unordered_map<int, unordered_set<int>> followMap;
    // tweet count
    int tc;
public:
    Twitter() {
        tc = 0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        // most recent one have less count
        // least recent has greater count
        tweetMap[userId].push_back({--tc, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        // tweet ids
        vector<int> tweets;
        // tc, tweet_id
        priority_queue<pair<int, int>> maxHeap;

        // most recent tweets should also contain user tweets as well
        follow(userId, userId);

        // get user followee
        for(const auto& followee: followMap[userId])
        {
            // get followee tweets
            for(const auto& tweet: tweetMap[followee])
            {
                // push followee tweets in heap
                maxHeap.push(tweet);
                // pop the least recent if heap size got bigger
                if(maxHeap.size() > 10)
                    maxHeap.pop();
            }
        }

        // push heap value in the heap
        // it will be arranged from least to most recent
        while (!maxHeap.empty()) {
            tweets.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        // reverse the tweets
        reverse(tweets.begin(), tweets.end());
        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/* 
------------------------------------------------------------------------------------
Question # 13 - Top k frequent Elements
------------------------------------------------------------------------------------
*/

class Solution {
public:
    class Compare
    {
        public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
        {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for(auto num: nums)
            freqMap[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;

        for(auto pair: freqMap)
            maxHeap.push(pair);

        vector<int> freq_elements;

        while(!maxHeap.empty() && freq_elements.size() < k)
        {
            freq_elements.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return freq_elements;
    }
};

/* 
------------------------------------------------------------------------------------
Question # 16 - Sort Array
------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto num: nums)
            minHeap.push(num);

        vector<int> sorted_arr;

        while(!minHeap.empty())
        {
            sorted_arr.push_back(minHeap.top());
            minHeap.pop();
        }

        return sorted_arr;
    }
};

/* 
------------------------------------------------------------------------------------
Question # 17 - Find points closest to origin
------------------------------------------------------------------------------------
*/

class Solution {
    typedef pair<int, pair<int, int>> pr;

    int euclideanDistance(int x2, int y2) 
    {
        int distance = (x2 * x2) + (y2 * y2);
        return distance;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pr> maxHeap;

        for(auto point: points)
        {
            int dist = euclideanDistance(point[0], point[1]);
            maxHeap.push({dist, {point[0], point[1]}});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> pairs;

        while(!maxHeap.empty())
        {
            int num1 = maxHeap.top().second.first;
            int num2 = maxHeap.top().second.second;
            pairs.push_back({num1, num2});
            maxHeap.pop();
        }

        return pairs;

    }
};

// ____________________________________ HASHING __________________________________________

/* 
------------------------------------------------------------------------------------
Question # 18 - Roman to Integer
------------------------------------------------------------------------------------
*/

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

/* 
------------------------------------------------------------------------------------
Question # 19 - Two Sum
------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // stores the num diff from taget and num index
        unordered_map<int, int> hashMap;
        vector<int> V;

        for(int i=0; i<nums.size(); i++)
        {
            int number = nums[i];
            int diff = target - number;

            // if diff doesn't exit, push it into map
            if(hashMap.count(diff) == 0)
                hashMap[nums[i]] = i;

            // if it is found then push the diff index and current index
            else 
            {
                V.push_back(hashMap[diff]);
                V.push_back(i);
                break;
            }
        }
        return V;
    }
};

/* 
------------------------------------------------------------------------------------
Question # 20 - Long Substring
------------------------------------------------------------------------------------
*/

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

/* 
------------------------------------------------------------------------------------
Question # 21 - Valid Sudoko
------------------------------------------------------------------------------------
*/

class Solution {
public:
    string getKey(int r, int c)
    {
        return to_string(r) + ", " + to_string(c);
    }

    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<string, unordered_set<char>> sub_boxes;

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                char val = board[r][c];

                // if box has no value continue
                if(val == '.') continue;
                // store sub_boxes with indexes 0, 1, 2.
                string subKey = getKey(r/3, c/3);

                // if value already exists in set return false
                if(
                    rows[r].count(val) ||
                    cols[c].count(val) ||
                    sub_boxes[subKey].count(val)
                  )
                  return false;

                rows[r].insert(val);
                cols[c].insert(val);
                sub_boxes[subKey].insert(val);
            }
        }

        return true;
    }
};

/* 
------------------------------------------------------------------------------------
Question # 22 - First Missing Integer
------------------------------------------------------------------------------------
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hashSet;

        // create a hashset; only put values which are > 0 
        // as we are looking for +ve int
        for(int num: nums)
        {
            if(num <= 0) continue;
            hashSet.insert(num);
        }

        // smallest integer should be in range 1 to n+1
        // if all n values present in arr then the smallest one
        // will be n+1
        int n = nums.size();
        for(int i = 1; i <= n+1; i++)
        {
            if(hashSet.count(i) == 0)
                return i;
        }

        // it never reach here
        return -1;
    }
};

/* 
------------------------------------------------------------------------------------
Question # 23 - Group Anagram
------------------------------------------------------------------------------------
*/

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

/* 
------------------------------------------------------------------------------------
Question # 24 - Zero Matrix
------------------------------------------------------------------------------------
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;
        
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (zeroRows.count(i) || zeroCols.count(j))
                    matrix[i][j] = 0;
            }
        }
        
    }
};

/* 
------------------------------------------------------------------------------------
Question # 25 - Minimum Window Substring
------------------------------------------------------------------------------------
*/

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
