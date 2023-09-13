using namespace std;

#include <vector>
#include <iostream>

class Solution {
public:
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

    void merge_sort(vector<int>& nums, int l, int r)
    {
        if(l == r) return;

        int mid = (l + r) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main()
{
    Solution sort;

    vector<int> nums({5, 2, 3, 1});
    vector<int> sorted_arr = sort.sortArray(nums);

    for(int num: sorted_arr)
        cout << num << " ";

    cout << endl;
}