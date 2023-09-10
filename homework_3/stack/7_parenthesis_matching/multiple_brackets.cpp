using namespace std;

#include <stack>
#include <string>
#include <unordered_map>


class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        unordered_map<char, char> closeToOpen ={
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c: s){
            if(!closeToOpen[c]) // if bracket is open
            { 
                bracketStack.push(c);
            } 
            else if(!bracketStack.empty() && bracketStack.top() == closeToOpen[c])
            {
                bracketStack.pop();
            } 
            else
            {
                return false;
            }
        }

        return bracketStack.empty();
    }
};
