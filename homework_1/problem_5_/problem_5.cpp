/*
Problem 5: Two Sum
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: twoSum
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Problem5 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> V;

        for(int i=0; i<nums.size(); i++)
        {

            int number = nums[i];
            int diff = target - number;

            if(hashMap.count(diff) == 0)
            {
                hashMap[nums[i]] = i;
            }
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

// Time Complexity = O(n)
// Space Complexity = O(n)

int main(){
    Problem5 problem_5;

    vector<int> V1({2,7,11,15});
    vector<int> V2({3, 2, 4});
    vector<int> V3({3, 3});
    vector<int> result;

    // Case 1: leetcode output should be [0, 1]
    result = problem_5.twoSum(V1, 9);
    cout<< "input '[2,7,11,15], 9' \noutput '[" << result[0] << "," << result[1] << "]' \n";

    // Case 2: loveleetcode output should be [1, 2]
    result = problem_5.twoSum(V2, 6);
    cout<< "input: '[3,2,4], 6' \noutput: '[" << result[0] << "," << result[1] << "]' \n";

    // Case 3: aabb output should be [0, 1]
    result = problem_5.twoSum(V3, 6);
    cout<< "input: '[3,3], 6' \noutput: '[" << result[0] << "," << result[1] << "]' \n";
}
