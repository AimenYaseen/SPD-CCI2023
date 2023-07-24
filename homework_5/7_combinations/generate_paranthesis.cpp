using namespace std;

#include <iostream>
#include <string>
#include <vector>

class Paranthesis {
    void generateParanthesis(int n, int open, int close, string str, vector<string>& res)
    {
        if(open == n && close == n)
        {
            res.push_back(str);
            return;
        }

        if(open < n)
        {
            generateParanthesis(n, open+1, close, str + '(', res);
        }
        if(close < open)
        {
            generateParanthesis(n, open, close+1, str+')', res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParanthesis(n, 0, 0, "", res);
        return res;
    }
};


int main(){
    Paranthesis p;
    vector<string> res = p.generateParenthesis(3);

    cout << "[ ";

    for(auto s: res)
    {
        cout << s << " ";
    }

    cout << "]" << endl; 
}