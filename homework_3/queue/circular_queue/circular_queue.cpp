using namespace std;

#include <iostream>

class MyCircularQueue {
    int* arr;
    int rear;
    int front;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        rear = -1;
        front = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(){
    MyCircularQueue* obj = new MyCircularQueue(3);
    // enQueue
    bool result = obj->enQueue(1);  // true
    result = obj->enQueue(2); // true
    result = obj->enQueue(3); // true
    result = obj->enQueue(4);  // false as queue is full

    int rear = obj->Rear(); // 4
    result = obj->isFull();

    result = obj->deQueue(); // true
    result = obj->enQueue(4); // true
    rear = obj->Rear(); // 4
}