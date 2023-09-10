using namespace std;

#include <stack>
#include<iostream>


class MinStack {
    stack<int> _stack, minStack;

public:
    MinStack() {}
    
    void push(int val) {
        
        _stack.push(val);

        if(minStack.empty() || val < getMin())
        {
            minStack.push(val);
        } 
        else 
        {
            minStack.push(getMin());
        }
    }
    
    void pop() {
        _stack.pop();
        minStack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */