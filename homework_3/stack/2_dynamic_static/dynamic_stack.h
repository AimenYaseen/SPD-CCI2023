#pragma once

template <typename T>
class DynamicStack{
    T* Vs;
    int capacity; // capacity of stack
    int size; // size of stack

    void reGrow(){
        T* newStack = new T[capacity*2];

        // copy Vs to newStack
        for(int i=0; i<capacity; i++){
            newStack[i] = Vs[i];
        }

        delete[]Vs;
        capacity *= 2;
        Vs = newStack;
    }

public:
    DynamicStack(int len){
        Vs = new T[len];
        capacity = len; 
        size = 0; 
    }

    bool push(T val){
        if(isFull()){
            reGrow(); // reGrow if it is full
        }

        Vs[size] = val;
        size++;
        return true;
    }

    bool pop(){
        if(isEmpty()){
            return false;
        }

        size--;
        return true;
    }

    // dangerous call if stack is empty
    T top(){
        return Vs[size - 1];
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }
};