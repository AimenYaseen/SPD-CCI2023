using namespace std;

#include <vector>
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

void merge_sort(vector<int>& nums, int l, int r)
{
    if(l == r) return;

    int mid = (l + r) / 2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    merge(nums, l, mid, r);
}

vector<int> removeDuplicates(vector<int>& nums)
{
    int n = nums.size() - 1;
    // sort array
    merge_sort(nums, 0, n); // O(nlogn)

    int t = 1;
    
    for(int i = 1; i <= n; i++) // O(n)
    {
        if(nums[i] != nums[i-1])
        {
            nums[t] = nums[i];
            t++;
        }
    }

    return vector<int>(nums.begin(), nums.begin()+t);
}

int main()
{
    vector<int> nums({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});

    vector<int> res = removeDuplicates(nums);

    for(auto r: res)
        cout << r << " ";

    cout << endl;
}