#pragma once

using namespace std;

#include <iostream>


class StaticQueue{
    int* items;
    int capacity;
    int front;
    int rear;

public:
    StaticQueue(int k){
        items = new int[k];
        capacity = k;
        front = rear = -1;
    }

    bool enQueue(int val){
        if(isFull()){
            return false;
        }

        if(front == -1){
            front++;
        }

        rear++;
        items[rear] = val;
        cout << "Pushed " << val << " at rear end " << endl;
        return true;
    }

    bool deQueue(){
        if(isEmpty()){
            return false;
        }
        cout << "Poped " << items[front] << " from front end " << endl;
        front++;
        return true;
    }

    int front_top(){
        if(isEmpty()){
            return -1;
        }
        cout << "Front: " << items[front] << endl;
        return items[front];
    }

    int rear_top(){
        if(isEmpty()){
            return -1;
        }
        cout << "Rear: " << items[rear] << endl;
        return items[rear];
    }

    bool isFull(){
        if(rear == capacity - 1){
            cout << "Queue is Full" << endl; 
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(rear == - 1){
            cout << "Queue is Empty" << endl; 
            return true;
        }
        return false;
    }
};