using namespace std;

#include <vector>
#include <algorithm>


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find x in array
        // get the lower bound
        // if value is not present, it returns the value just greater than the target
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx;

        // if target is smaller than the arr first element
        // then the pivot is 0 index
        if(it == arr.begin())
            idx = 0;
        // if target is greater than the last element in arr 
        // then last index will be the pivot
        else if(it == arr.end())
            idx = arr.size() - 1;
        else
        {
            // if value = target or greater than target
            // find absolute difference
            // if current is less or equal then this is the index
            // otherwise previous will be the index
            int curDiff = abs(*it - x);
            int prevDiff = abs(*(it - 1) - x);
            idx = curDiff < prevDiff ? it - arr.begin() : (it - 1)  - arr.begin();
        }

        // assign l & r to pivot index
        int l = idx, r = idx;

        for (int i = 0; i < k - 1; ++i) 
        {
            // if l at index 0
            if (l == 0)
                ++r;
            else if (r == arr.size() - 1 || x - arr[l - 1] <= arr[r + 1] - x) 
                --l;
            else
                ++r;
        }

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);

    }
};