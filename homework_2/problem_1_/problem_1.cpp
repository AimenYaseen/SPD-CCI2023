/*
Problem 1: Sort Colors
●  Difficulty: Medium
●  Estimated Time: 60 minutes
●  Problem Link: https://leetcode.com/problems/sort-colors
*/

#include <iostream>
#include <vector>

using namespace std;

class Problem1 {
public:
    void sortColors(vector<int>& nums) {
        int start=0, end=nums.size()-1;
        int index = 0;

        while(index<=end){
            if(nums[index] == 0){
                nums[index] = nums[start];
                nums[start] = 0;
                start++;
                index++;
            } else if(nums[index] == 2){
                nums[index] = nums[end];
                nums[end] = 2;
                end--;
            } else {
                index++;
            }
        }
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
    Problem1 problem_1;

    vector<int> V1({2,0,2,1,1,0});
    vector<int> V2({2, 0, 1});

    // Case 1: leetcode output should be [0,0,1,1,2,2]
    problem_1.sortColors(V1);
    print_vector(V1);

    // Case 2: loveleetcode output should be [0, 1, 2]
    problem_1.sortColors(V2);
    print_vector(V2);
}
