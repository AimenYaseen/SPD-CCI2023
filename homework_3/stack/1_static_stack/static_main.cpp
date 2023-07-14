using namespace std;

#include <iostream>
#include "static_stack.h"

int main(){
    StaticStack<int> stack(5);

    // push values
    cout << "Push 10: " << stack.push(10) << endl;
    cout << "Push 1: " << stack.push(1) << endl;
    cout << "Push 6: " << stack.push(6) << endl;
    cout << "Push -1: " << stack.push(-1) << endl;
    cout << "Push 9: " << stack.push(9) << endl;
    cout << "Push 18: " << stack.push(18) << endl; // returns false

    // top
    if (!stack.isEmpty())
    {
        cout << "Stack top: " << stack.top() << endl; // 9
    }

    // pop
    cout << "Pop 9: " << stack.pop() << endl;
    cout << "Pop -1: " << stack.pop() << endl;
    cout << "Pop 6: " << stack.pop() << endl;

    // top
    if (!stack.isEmpty()){
        cout << "Stack top: " << stack.top() << endl; // 1
    }

    // pop
    cout << "Pop 1: " << stack.pop() << endl;
    cout << "Pop 10: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl; // prints false

    // top => it will not be executed as stack is empty
    if (!stack.isEmpty()){
        cout << "Stack top: " << stack.top() << endl; 
    }
}
