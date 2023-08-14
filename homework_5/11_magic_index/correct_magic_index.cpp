/*
A magic index in an array A[0 … n-1] is defined to be an index such that A[i] = i. 
Given a sorted array of distinct sorted integers, 
write a method to find a magic index, if one exists, in array A. 
FOLLOW UP - What if the integers are not distinct?
*/

using namespace std;

#include <iostream>
#include <vector>


int magic_index(int left, int right, vector<int> numbers)
{
    int mid = (left + right) / 2; // mid index

    if(left > right) // if magic index is not found
        return -1;

    if(numbers[mid] == mid) // if magic index is found
        return mid;

    else if(numbers[mid] > mid)
        return magic_index(mid + 1, right, numbers);
    else
        return mid;  // if mid number == mid index return

    if(numbers[mid] > mid)
        left = mid + 1;

    if(numbers[mid] < mid)
        right = mid - 1;

    int ans = magic_index(left, right, numbers);

    if(ans != -1)
        return ans;

    ans = magic_index(left, right, numbers);
    return ans;
}


int main()
{
    // Case 1: Magic index of {-1, 0, 2, 7, 8}
    vector<int> numbers({-1, 0, 2, 7, 8});
    cout << "Magic index of {-1, 0, 2, 7, 8} is " << magic_index(0, numbers.size()-1, numbers) << endl; // 2

    // Case 2: Magic index of {-10, 0, 1, 1, 4, 20}
    vector<int> numbers2({-10, 0, 1, 1, 4, 20});
    cout << "Magic index of {-10, 0, 1, 1, 4, 20} is " << magic_index(0, numbers2.size()-1, numbers2) << endl; // -1
}

/*
The above solution has a problem.
{-10, 0, 1, 1, 4, 20} // It will return -1 in this case but the correct answer is 4.
*/ 