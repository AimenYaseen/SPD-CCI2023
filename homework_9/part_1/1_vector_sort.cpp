#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // enter vector size
    int size;
    cin >> size;
    
    vector<int> ints;
    int num;
    
    // enter vector elements
    for(int i=0; i<size; i++)
    {
        cin >> num;
        ints.push_back(num);
    }   
    
    sort(ints.begin(), ints.end());
    
    // print vector elements
    for(int i=0; i<size; i++)
        cout << ints[i] << " ";
    
    return 0;
}
