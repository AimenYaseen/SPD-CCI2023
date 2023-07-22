/*
All Subsets of a Set of Size n: 
Write a method to generate all subsets of a set of size n.
*/

using namespace std;

#include <iostream>
#include <vector>


vector<vector<int>> AllSubsets(vector<int>& Vs)
{
    int size = Vs.size();

    if(size == 0) // base case: return {{}} if n reaches 0
    {
        return vector<vector<int>>(1);
    }

    int n = Vs[size-1];
    Vs.pop_back();

    auto subsets = AllSubsets(Vs);
    auto power_set = subsets;

    for(auto set: subsets)
    {
        set.push_back(n);
        power_set.push_back(set);
    }

    return power_set;
}


int main()
{
    vector<int> numbers({1, 2, 3});
    vector<vector<int>> subsets = AllSubsets(numbers);

    cout << "Power set for {1, 2, 3}" << endl;
    cout << "{" << endl;

    for(auto set: subsets)
    {
        cout << "{ ";
        for(auto s: set)
        {
            cout << s << " ";
        }
        cout << "}" << endl;
    }

    cout << "}" << endl;
}