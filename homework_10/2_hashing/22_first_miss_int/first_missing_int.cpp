using namespace std;

#include<vector>
#include<unordered_set>


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