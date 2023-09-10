using namespace std;

#include <iostream>
#include <vector>

void selectionSort(vector<int>& arr, int n, int index) 
{
    // Base case: Reached the end of the array
    if (index == n - 1)
        return;

    int minIndex = index;

    // Find the index of the minimum element in the unsorted part
    for (int i = index + 1; i < n; ++i) 
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    // Swap the minimum element with the first element of the unsorted part
    swap(arr[index], arr[minIndex]);

    // Recursively sort the remaining unsorted part
    selectionSort(arr, n, index + 1);
}

int main() 
{
    vector<int> array = {64, 25, 12, 22, 11};
    int n = array.size();

    cout << "Original array: ";
    for (int num : array) 
        cout << num << " ";
    cout << endl;

    selectionSort(array, n, 0);

    cout << "Sorted array: ";
    for (int num : array) 
        cout << num << " ";
    cout << endl;

    return 0;
}
