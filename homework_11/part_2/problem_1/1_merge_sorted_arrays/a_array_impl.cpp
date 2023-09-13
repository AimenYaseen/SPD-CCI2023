using namespace std;

#include <vector>
#include <iostream>


int* merge(int nums1[], int n1, int nums2[], int n2)
{
    // Dynamically allocate memory
    int* nums = new int[n1 + n2];

    // pointers
    int i = 0, j = 0, k = 0;

    while(j < n1 && k < n2)
    {
        if(nums1[j] <= nums1[k])
        {
            nums[i] = nums1[j];
            j++;
        }
        else 
        {
            nums[i] = nums2[k];
            k++;
        }
        i++;
    }

    while(j < n1)
    {
        nums[i] = nums1[j];
        j++;
        i++;
    }

    while(k < n2)
    {
        nums[i] = nums2[k];
        k++;
        i++;
    }

    return nums;
}


int main()
{

    int nums1[4] = {1, 5, 8, 9};
    int nums2[3] = {2, 6, 7};
    int* sorted_arr = merge(nums1, 4, nums2, 3);

    for (int i = 0; i < 7; i++)
      cout << *(sorted_arr + i) << " ";

    cout << endl;
}
