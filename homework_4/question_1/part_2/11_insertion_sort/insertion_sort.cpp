using namespace std;

#include <iostream>
#include <vector>

void insertionSort(vector<int>& arr, int n) 
{
    // Base case: Array of size 1 or less is already sorted
    if (n <= 1)
        return;  

    // Recursively sort the smaller subarray
    insertionSort(arr, n - 1);

    // Insert the last element of the current subarray into its correct position
    int lastElement = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > lastElement) 
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = lastElement;
}

int main() 
{
    vector<int> array = {64, 25, 12, 22, 11};
    int n = array.size();

    cout << "Original array: ";
    for (int num : array)
        cout << num << " ";
    cout << endl;

    insertionSort(array, n);

    cout << "Sorted array: ";
    for (int num : array)
        cout << num << " ";
    cout << endl;

    return 0;
}
