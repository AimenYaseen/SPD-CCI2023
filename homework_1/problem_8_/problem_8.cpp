/*
Problem 8: Rotate Array
●  Difficulty: Medium
●  Estimated Time: 60 minutes
●  Problem Link: https://leetcode.com/problems/rotate-array
*/

#include <iostream>
#include <vector>

using namespace std;

class Problem8 {
private:
    void reverse_arr(vector<int>& nums, int l, int r) {
        while(l <= r){
            swap(nums[l], nums[r]);
            l += 1;
            r -= 1;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        // k = nums.size() then there will be no rotation
        k %= nums.size();

        // reverse the entire array
        reverse_arr(nums, 0, nums.size() - 1 );

        // reverse first k portion
        reverse_arr(nums, 0, k - 1);

        // reverse remaining portion
        reverse_arr(nums, k, nums.size() - 1);
    }
};

// Time Complexity = O(n)
// Space Complexity = O(1)

void print_vector(vector<int>& vec){
    cout<<'[';
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ' ';
        cout<<',';
    }
    cout<<']'<<endl;
}

int main(){
    Problem8 problem_8;

    vector<int> V1({1,2,3,4,5,6,7});
    vector<int> V2({-1,-100,3,99});

    // Case 1: leetcode output should be [5,6,7,1,2,3,4]
    problem_8.rotate(V1, 3);
    print_vector(V1);

    // Case 2: loveleetcode output should be [3,99,-1,-100]
    problem_8.rotate(V2, 2);
    print_vector(V2);
}
