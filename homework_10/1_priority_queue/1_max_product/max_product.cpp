using namespace std;

#include<vector>
#include<queue>

class Solution {
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