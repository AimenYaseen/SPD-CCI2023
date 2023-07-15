using namespace std;

#include <stack>


class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() { 
    }
    
    void push(int x) {
        s1.push(x);
    }

    void populate_stack(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        int val = peek();
        s2.pop();
        return val;
    }
    
    int peek() {
        if(!empty()){
            if(s2.empty()){
                populate_stack();
            }
            return s2.top(); 
        }
        return 0;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */