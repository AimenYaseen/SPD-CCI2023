using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>


void swap(vector<int>& a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void ProfJunaidSort(vector<int>& a, int min, int max) 
{
    if (min > max) 
        return;

    if (a[min] > a[max]) 
        swap(a, min, max);
    
    int oneThird = (max - min + 1) / 3;
    if (oneThird >= 1) 
    {
        ProfJunaidSort(a, min, max - oneThird);
        ProfJunaidSort(a, min + oneThird, max);
        ProfJunaidSort(a, min, max - oneThird);
    }
}

/*
    In Nutshells the sorting algorithm says:
    1. Sort first 2/3rd of the array (by calling BabaG)
    2. Sort the last 2/3rd of the array (BabaG again)
    3. Sort the first 2/3rd of the array (BabaG again)
*/
void ProfJunaidSort(vector<int>& a) 
{
    ProfJunaidSort(a, 0, a.size() - 1);
}

// Test this on a certain vector of let us say size 9
int main()
{
    vector<int> arr = {9, 2, 5, 7, 1, 8, 4, 6, 3};
    ProfJunaidSort(arr);

    for(auto n: arr)
        cout << n << " ";

    cout << endl;
}

