using namespace std;

#include <iostream>
#include <vector>

void bubbleSort(vector<int>& arr, int n) 
{
    // Base case: Array of size 1 is already sorted
    if (n == 1)
        return;  

    for (int i = 0; i < n - 1; ++i) 
    {
        // Swap if the elements are in the wrong order
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    // Recursively sort the remaining elements
    bubbleSort(arr, n - 1); 
}

int main() 
{
    vector<int> array = {64, 34, 25, 12, 22, 11, 90};
    int n = array.size();

    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    bubbleSort(array, n);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
