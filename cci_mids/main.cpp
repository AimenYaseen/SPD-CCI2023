#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// This is where the actual implementation of 
// the solution lies. Modify this function according to 
// your needs
int myFunc(vector<int>& input) {
    return 0;
}


// This function prints the output of a single case
// in the required format. Modify this according to 
// the questions required output format.
void printCaseOutput(int output) {
    
    // In this case its just an int so we'll print it
    // and put a endl at the end;
    cout << output << " " << endl;
}

// This is the engine code which takes the whole inputs 
// array then proceeds one test case 
// at a time. Gives it to 'myFunc()' to get the answer
// and then passes on the output to 'printCaseOutput'to
// print the output for individual case prefixing it the
// Case #{i+1}:  
// Modify it according to each questions needs.
void solve(vector<vector<int>>& inputs) {
    int nInputs = inputs.size();
    for(int i = 0; i < nInputs; i++) {
        auto output = myFunc(inputs[i]);
        cout << "Case #" << i+1 << ": "; 
        printCaseOutput(output);
    }
}


// This function takes input for all the test-cases
// in one go and returns a vector where each value
// represents the input of 1 case. 
// Modify it according to the question's requirements. 
vector<vector<int>> takeInput() {
    // Total number of testcases. 
    int testCases;
    cin >> testCases;
    
    vector<vector<int>> inputs(testCases);
    
    // Loop testCases times to take input for each case
    while(testCases--) {
        
        // The length of the input array for this case;
        int length; 
        cin >> length;
        
        // Declare an array with length size
        vector<int> inputArray(length);
        
        
        // Input each element in the array
        for(int i = 0; i < length; i++) {
            cin >> inputArray[i];
        }
        
        // Push the current test case array in 
        // the main inputs array which contains
        // all test cases. 
        inputs.push_back(inputArray);
    }
    
    return inputs;
}

int main() {
    // Take input all at once
    auto testCases = takeInput(); 
    
    // pass it to the engine to solve once 
    // case at a time.
    solve(testCases);
    return 0;
}