using namespace std;

#include <vector>
#include <queue>
#include <iostream>


void merge(vector<int>& nums, int l, int m, int r)
{
    vector<int> left_arr(nums.begin() + l, nums.begin() + m + 1);
    vector<int> right_arr(nums.begin() + m + 1, nums.begin() + r + 1);

    int la = m - l + 1, ra = r - m;

    // pointers
    int i = l, j = 0, k = 0;

    while(j < la && k < ra)
    {
        if(left_arr[j] <= right_arr[k])
        {
            nums[i] = left_arr[j];
            j++;
        }
        else 
        {
            nums[i] = right_arr[k];
            k++;
        }
        i++;
    }

    while(j < la)
    {
        nums[i] = left_arr[j];
        j++;
        i++;
    }

    while(k < ra)
    {
        nums[i] = right_arr[k];
        k++;
        i++;
    }
}



void iterativeMergeSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int b = 1; b <= n - 1; b *= 2) 
    {
        for (int i = 0; i < n - 1; i += 2 * b) 
        {
            int right = min(i + 2 * b - 1, n - 1);
            int mid = min(i + b - 1, n - 1);
            merge(arr, i, mid, right);
        }
    }
}


int main()
{
    vector<int> nums = {5, 3, 2, 1};

    iterativeMergeSort(nums);

    for (int num : nums)
        cout << num << " ";

}
