/*
Problem 4: Search Insert Position
●  Difficulty: Easy
●  Estimated Time: 30 minutes
●  Problem Link: searchInsertPosition
*/

#include <iostream>
#include <vector>

using namespace std;

class Problem4 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(target == nums[mid]){
                return mid;
            }else if(target > nums[mid]){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

// Time Complexity = O(log n)
// Space Complexity = O(1)

int main(){
    Problem4 problem_4;

    vector<int> V1({1,3,5,6});

    // Case 1: leetcode output should be 2
    int return_value = problem_4.searchInsert(V1, 5);
    cout<< "input \'[1,3,5,6], 5' \noutput \'" << return_value << "\' \n";

    // Case 2: loveleetcode output should be 1
    return_value = problem_4.searchInsert(V1, 2);
    cout<< "input: \'[1,3,5,6], 2' \noutput: \'" << return_value << "\' \n";

    // Case 3: aabb output should be 4
    return_value = problem_4.searchInsert(V1, 7);
    cout<< "input: \'[1,3,5,6], 7' \noutput: \'" << return_value << "\' \n";
}