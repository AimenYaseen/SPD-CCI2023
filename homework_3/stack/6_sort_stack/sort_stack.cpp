using namespace std;

#include <iostream>
#include <stack>
#include <vector>


class SortedStack{
    stack<int> s;
public:
    SortedStack(vector<int> v){
        for(int num: v){
            s.push(num);
        }
    }

	void sort(){
        stack<int> s2;
        
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            while(!s2.empty() && s2.top() < temp)
            {
                s.push(s2.top());
                s2.pop();
            }
            s2.push(temp);
        };
        
        cout<<endl<<"Output: {";
        while(!s2.empty()){
            int num = s2.top();
            s2.pop();
            cout<<num;
            cout<<", ";
        }
        cout<<"}";
            
    }
};


int main(){
    vector<int> v1({34, 3, 31, 98, 92, 23});
    SortedStack sorted_stack(v1);

    // Case 1: {34, 3, 31, 98, 92, 23} => {3, 23, 31, 34, 92, 98}
    cout<<"Input: {34, 3, 31, 98, 92, 23}";
    sorted_stack.sort();

}