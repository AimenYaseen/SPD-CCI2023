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

int main() 
{
    vector<int> arr = {3, 8, 1, 4, 7, 2, 9, 5, 6};
    int n = arr.size();

    int pivotIndex = randomPartition(arr, 0, n - 1);

    cout << "Pivot Index: " << pivotIndex << ", Pivot Value: "<< arr[pivotIndex] << endl;
    cout << "Partitioned Array: ";
    for (int num : arr)
        cout << num << " ";
}