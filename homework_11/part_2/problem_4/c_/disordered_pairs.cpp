using namespace std;

#include <vector>
#include <iostream>

void getDisorderedPairs(vector<vector<int>>& pairs, vector<int> left_arr, int l, int r_value)
{
    for(int i = l; i < left_arr.size(); i++)
    {
        pairs.push_back({left_arr[i], r_value});
    }
}


void merge(vector<int>& nums, int l, int m, int r, int &inv, vector<vector<int>>& pairs)
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
            getDisorderedPairs(pairs, left_arr, j, right_arr[k]);
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

void merge_sort(vector<int>& nums, int l, int r, int &inv, vector<vector<int>>& pairs)
{
    if(l == r) return;

    int mid = (l + r) / 2;
    merge_sort(nums, l, mid, inv, pairs);
    merge_sort(nums, mid + 1, r, inv, pairs);
    merge(nums, l, mid, r, inv, pairs);
}

int main()
{
    int inv = 0;
    vector<int> nums({5, 2, 3, 1});
    vector<vector<int>> pairs;

    merge_sort(nums, 0, nums.size() - 1, inv, pairs);
    cout << endl << "Inversion: " << inv << endl; // 5

    for(auto pair: pairs)
    {
        cout << "( " << pair[0] << ", " << pair[1] << " )" << endl;
    }

    cout << endl;
}