/*
Problem 9: Find Peak
●  Difficulty: Medium
●  Estimated Time: 60 minutes
●  Problem Link: https://leetcode.com/problems/find-peak-element
*/

#include <iostream>
#include <vector>

using namespace std;

class Problem9 {
public:
    int findPeakElement(vector<int>& nums) {
        int l= 0, r = nums.size() - 1;

        while(l <= r){
            int mid = (l + r)/2;

            // check if left side is greater
            if(mid > 0 && nums[mid] < nums[mid - 1]){
                r = mid - 1;
            }
            else if(mid < (nums.size()-1) && nums[mid] < nums[mid + 1])
            {
                // check if right side is greater
                l = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};

// Time Complexity = O(log n)
// Space Complexity = O(1)

int main(){
    Problem9 problem_9;

    vector<int> V1({1,2,3,1});
    vector<int> V2({1,2,1,3,5,6,4});

    // Case 1: leetcode output should be 2
    int return_value = problem_9.findPeakElement(V1);
    cout<< "input '[1,2,3,1]' \noutput '" << return_value << "' \n";

    // Case 2: loveleetcode output should be 5
    return_value = problem_9.findPeakElement(V2);
    cout<< "input '[1,2,1,3,5,6,4]' \noutput '" << return_value << "' \n";
}
