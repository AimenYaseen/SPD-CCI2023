using namespace std;

#include <vector>
#include <iostream>


vector<int> merge(vector<int>& nums1, vector<int>& nums2)
{
    int la = nums1.size(), ra = nums2.size();
    vector<int> nums(la+ra, 0);

    // pointers
    int i = 0, j = 0, k = 0;

    while(j < la && k < ra)
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

    while(j < la)
    {
        nums[i] = nums1[j];
        j++;
        i++;
    }

    while(k < ra)
    {
        nums[i] = nums2[k];
        k++;
        i++;
    }

    return nums;
}


int main()
{

    vector<int> nums1({1, 5, 8, 9});
    vector<int> nums2({2, 6, 7});
    vector<int> sorted_arr = merge(nums1, nums2);

    for(int num: sorted_arr)
        cout << num << " ";

    cout << endl;
}