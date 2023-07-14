using namespace std;

#include <iostream>
#include <vector>


class MinStack {
    vector<int> _stack, minStack;

public:
    MinStack() {}
    
    void push(int val) {

        if(minStack.size() == 0 || val < getMin())
        {
            minStack.push_back(val);
        } 
        else 
        {
            minStack.push_back(getMin());
        }

        _stack.push_back(val);
    }
    
    void pop() {
        _stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return _stack[_stack.size() - 1];
    }
    
    int getMin() {
        return minStack[_stack.size() - 1];
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