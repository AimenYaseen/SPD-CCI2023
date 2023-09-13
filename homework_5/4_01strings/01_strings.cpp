/*
All 0/1 Strings of Length n: 
Write a method to generate all 0/1 strings of length n.
*/

using namespace std;

#include <iostream>
#include <vector>


vector<string> generate_01_strings(int n)
{
    if( n == 0) // base case; if n = 0 return empty string
    {
        vector<string> emptyString({""});
        return emptyString;
    }

    vector<string> allStrings = generate_01_strings(n-1);

    vector<string> subStrings;
    // append 0 and then 1 at front to get output in order
    for(string s: allStrings)
    {
        subStrings.push_back("0" + s);
    }

    for(string s: allStrings)
    {
        subStrings.push_back("1" + s);
    }

    return subStrings;
}


void print_strings(int len, vector<string> resultedStrings){
    cout << "Strings of length " << len << "\n\n";

    for(auto s: resultedStrings)
    {
        cout << s << endl;
    }
    cout << endl;
}


int main()
{
    // Case 1: strings of length 3
    vector<string> resultedStrings = generate_01_strings(3);
    print_strings(3, resultedStrings);

    // Case 2: strings of length 4
    resultedStrings = generate_01_strings(4);
    print_strings(4, resultedStrings);

}


// n = 3 return {"000", "001", "010", "011", "100", "101", "110", "111"}
// n = 2 return {"00", "01", "10", "11"}
// n = 1 return {"0", "1"}
// n = 0 return {""} ; stack => last in first out
