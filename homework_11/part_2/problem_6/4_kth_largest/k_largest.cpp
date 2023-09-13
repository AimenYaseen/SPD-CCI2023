using namespace std;

#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

class Solution {
public:
    int randomPivot(int s, int r)
    {
        srand(time(0));
        return s + rand() % (r - s + 1);
    }


    int randomPartition(vector<int>& nums, int s, int e)
    {
        int pivotIndex = randomPivot(s, e);
        // move pivot to end
        swap(nums[pivotIndex], nums[e]);

        int pivot = nums[e];
        int i = s - 1;

        for(int j = s; j < e; j++)
        {
            if(nums[j] >= pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        // move pivot index
        swap(nums[i+1], nums[e]);
        return i+1;
    }

    void quickSort(vector<int>& nums, int s, int e)
    {
        if(s > e)
            return;

        int p = randomPartition(nums, s, e);
        quickSort(nums, s, p - 1);
        quickSort(nums, p + 1, e);
    }

    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums[k - 1];
    }
};