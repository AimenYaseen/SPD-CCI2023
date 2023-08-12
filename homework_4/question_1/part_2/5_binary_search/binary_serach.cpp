using namespace std;

#include <iostream>
#include <vector>


int binarySearch(const vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1;  // Target value not found
    }

    int mid = (left + right) / 2;

    if (arr[mid] == target) 
        return mid;  // Target value found at index mid
    else if (arr[mid] < target) 
        return binarySearch(arr, mid + 1, right, target);  // Search the right half
    else 
        return binarySearch(arr, left, mid - 1, target);  // Search the left half
}

int main() 
{
    // return index start from 0
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int targetValue = 7;
    int result = binarySearch(sortedArray, 0, sortedArray.size() - 1, targetValue);
    
    if (result != -1)
        cout << "Index of the target value: " << result << endl;
    else
        cout << "Target value not found in the array." << endl;

    return 0;
}
