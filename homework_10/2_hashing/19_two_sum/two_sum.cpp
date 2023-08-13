using namespace std;

#include <string>
#include <unordered_map>
#include <vector>


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