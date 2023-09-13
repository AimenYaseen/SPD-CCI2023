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
    
    // enter first query
    int p1, p2;
    cin >> p1;
    
    // erase 1st query element
    ints.erase(ints.begin()+(p1 - 1));
    
    cin >> p1 >> p2;
    // erase range of elements
    ints.erase(ints.begin()+(p1 - 1), ints.begin()+(p2 - 1));
    
    size = ints.size();
    cout << size << endl;
    
    // print vector elements
    for(int i=0; i<size; i++)
        cout << ints[i] << " ";
    
    return 0;
}

