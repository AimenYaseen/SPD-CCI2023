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
    
    vector<int> numbers;
    int num;
    
    // enter vector elements
    for(int i=0; i<size; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }  
    
    // enter number of queries
    int q; 
    cin >> q;
    
    while(q)
    {
        cin >> num;
        
        auto it = lower_bound(numbers.begin(), numbers.end(), num);
        
        if(*it == num)
            cout << "Yes " << it + 1 - numbers.begin() << endl;
        else
            cout << "No " << it + 1 - numbers.begin() << endl;
        
        q--;
    } 
    
    return 0;
}

