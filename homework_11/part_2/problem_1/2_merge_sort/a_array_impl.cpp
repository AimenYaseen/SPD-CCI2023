using namespace std;

#include <vector>
#include <iostream>

class Solution {
public:
    void merge(int nums[], int l, int m, int r)
    {
        int la = m - l + 1, ra = r - m;

        int left_arr[la];
        int right_arr[ra];

        for(int i=0; i<la; i++)
            left_arr[i] = nums[l+i];

        for(int i=0; i<ra; i++)
            right_arr[i] = nums[m+1+i];

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

    void merge_sort(int nums[], int l, int r)
    {
        if(l == r) return;

        int mid = (l + r) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    void sortArray(int nums[], int size) {
        merge_sort(nums, 0, size - 1);
    }
};


int main()
{
    Solution sort;

    int size = 5;
    int nums1[] = {5, 1, 8, 9, 0};
    sort.sortArray(nums1, size);

    for (int i = 0; i < size; ++i) {
        cout << nums1[i] << " ";
    }

    cout << endl;
}