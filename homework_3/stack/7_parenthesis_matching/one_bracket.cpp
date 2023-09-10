using namespace std;

#include <iostream>


class BracketMatching {
public:
    bool is_valid_brackets(string s){
        int valid = 0;

        for(char c : s){
            if(valid == -1){
                return false;
            }else if(c == '('){
                valid++;
            } else if (c == ')'){
                valid--;
            }
        }
        return true;
    }
};


int main(){
    BracketMatching bracket_matching;

    cout<< "Valid parenthesis?"<<endl;

    // Case 1: Output should be false
    bool return_value = bracket_matching.is_valid_brackets("(((()))))()");
    cout<< "input: '(((()))))()' \noutput: '" << return_value << "' \n";

    // Case 2: Output should be true
    return_value = bracket_matching.is_valid_brackets("(((())))()");
    cout<< "input: '(((())))()' \noutput: '" << return_value << "' \n";
}
