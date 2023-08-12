using namespace std;

#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_set>


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++)
        {
            if(m.count(nums[i]) != 0)
            {
                int index = m[nums[i]];
                if(abs(index - i) <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};