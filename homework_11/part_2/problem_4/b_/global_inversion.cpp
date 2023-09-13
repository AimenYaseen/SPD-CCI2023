using namespace std;

#include <vector>
#include <iostream>


void merge(vector<int>& nums, int l, int m, int r, int &inv)
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
            // nums[j] > nums[k] ; if nums[j] is greater then all the coming elements will also be greater
            // [3 4 5] [1 2 7]
            // as 3 > 1; there will be 1 entropy
            // Also if 3 > 1 then the coming 4, 5 will also be greater
            // as they are two sorted arrays
            // do the entropy will become: 3-0 = 3
            inv += la - j;
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

void merge_sort(vector<int>& nums, int l, int r, int &inv)
{
    if(l == r) return;

    int mid = (l + r) / 2;
    merge_sort(nums, l, mid, inv);
    merge_sort(nums, mid + 1, r, inv);
    merge(nums, l, mid, r, inv);
}

int main()
{
    int inv = 0;
    vector<int> nums({5, 2, 3, 1});
    merge_sort(nums, 0, nums.size() - 1, inv);
    cout << endl << "Inversion: " << inv << endl; // 5
}