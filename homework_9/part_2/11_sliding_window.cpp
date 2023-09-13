using namespace std;

#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<deque>


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         deque<int> window;
         vector<int> maximum;

        // initializes left or right pointer
         int l = 0, r = 0;

        // continue until right reaches at end
         while(r < nums.size())
         {
            // remove values from queue back if it is smaller than current pos and queue is not empty
            while(!window.empty() && nums[r] > nums[window.back()])
                window.pop_back();

            // here we get the greater value so push it
            window.push_back(r);

            // let's suppose we have 9, 5 in queue right now
            // 9 is the last windows max.
            // 5 is the current window max
            // 9 didn't pop because it is > 5.
            // so, we check if l pointer > queue top index which is 9
            // if it is then we pop from front
            if(l > window.front())
                window.pop_front();

            // this condition will not executed only for first k iterations
            // because we have to find the first max.
            // after that we just need to check last element of window
            // as we checked previous already
            if(r >= k - 1)
            {
                maximum.push_back(nums[window.front()]);
                l++;
            }
            r++;
         }

         return maximum;
    }
};