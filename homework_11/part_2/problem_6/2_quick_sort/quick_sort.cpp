using namespace std;

#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>


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
        if(nums[j] <= pivot)
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

int main() 
{
    vector<int> arr = {3, 8, 1, 4, 7, 2, 9, 5, 6};
    int n = arr.size();

    quickSort(arr, 0, n-1);
    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
}

/*
Time Complexity Analysis:

Average Time Complexity: O(n log n)
Worst Case Time Complexity: O(n^2)

In Quick Sort, on average, each element is compared and swapped around 
log n times for n elements, resulting in an average time complexity of
O(n log n). However, in the worst case (e.g., when the array is already
sorted or nearly sorted), the partition step may lead to skewed partitions,
causing the algorithm to perform poorly with a time complexity of O(n^2). 
The worst case can be improved by using randomized algorithms to choose the pivot.

So, in this case average & worst time complexity in O(nlogn).
*/