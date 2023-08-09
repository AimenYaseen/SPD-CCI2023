#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<vector<int>> RGeneratePowerSet(vector<int> &PV, int size)
{
    // base case
    if(size == 0)
    {
        // if there is no element left than return the empty set
        vector<vector<int>> ES ({{}});
        return ES;
    }

    int last = PV[size - 1]; // store the last element
    auto subsets = RGeneratePowerSet(PV, size - 1); // calculate subsets of n-1 elements
    auto power_set = subsets; 

    for(auto set: subsets)
    {
        set.push_back(last); 
        power_set.push_back(set);
    }

    return power_set;
}


vector<vector<int>> GeneratePowerSet(vector<int> V)
{
    return RGeneratePowerSet(V, V.size());
}


int main()
{
    vector<int> V({1, 2, 3});
    auto power_set = GeneratePowerSet(V);
    power_set[0] = {-1};

    for(int i=0; i<power_set.size(); i++)
    {
        for(int j=0; j<power_set[i].size(); j++)
        {
            cout << power_set[i][j];
        }

        cout << endl;
    }
}