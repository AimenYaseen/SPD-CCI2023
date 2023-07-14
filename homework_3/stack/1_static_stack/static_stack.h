#pragma once

template <typename T>
class StaticStack{
    T* Vs;
    int size; // size of stack
    int index; // points to top of stack

public:
    StaticStack(int len){
        Vs = new T[len];
        size = len; 
        index = 0; 
    }

    bool push(T val){
        if(isFull()){
            return false;
        }

        Vs[index] = val;
        index++;
        return true;
    }

    bool pop(){
        if(isEmpty()){
            return false;
        }

        index--;
        return true;
    }

    // dangerous call if stack is empty
    T top(){
        return Vs[index - 1];
    }

    bool isEmpty(){
        return index == 0;
    }

    bool isFull(){
        return index == size;
    }
};