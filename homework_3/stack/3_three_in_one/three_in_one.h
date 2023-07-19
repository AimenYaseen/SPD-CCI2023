#pragma once

using namespace std;

#include <iostream>

// template <typename T>
class ThreeStacks{
    int* items;
    // assume capacity is always the multiple of stack_size 
    int capacity;  // array size
    int stack_size; // each stack size
    int stack_num; // number of stacks to be implemented
    int* stack_top; // stack top index

public:
    ThreeStacks(int size, int k){
        items = new int[size];
        capacity = size;
        stack_num = k;
        stack_size = size / k;
        stack_top = new int[k];

        // Initialize all stacks as empty
        for (int i = 0; i < k; i++)
            stack_top[i] = 0;
    }

    void push(int sn, int val){
        if(isFull(sn)){
            return;
        }

        items[(sn * stack_size) + stack_top[sn]] = val;
        stack_top[sn]++;

        cout << "Pushed " << val << " in stack " << sn << endl;
    }

    void pop(int sn){
        if(isEmpty(sn)){
            return;
        }
        cout << "Poped " << items[(sn * stack_size) + stack_top[sn] - 1] << " from stack " << sn << endl;
        stack_top[sn]--;
    }

    void top(int sn){
        if(isEmpty(sn)){
            return;
        }
        cout << "Stack Number " << sn << " top element is " << items[(sn * stack_size) + stack_top[sn] - 1] << "\n";
        return ;
    }

    bool isFull(int sn){
        if(sn < 0 || sn >= stack_num)
        {
            cout << "\nInvalid Stack Number, Stack number should be in range 0 to k-1\n\n";
            return true;
        } 
        else if(stack_top[sn] == stack_size)
        {
            cout << "Stack Number " << sn << " is Full\n";
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty(int sn){
        if(sn < 0 || sn >= stack_num){
            cout << "\nInvalid Stack Number, Stack number should be in range 0 to k-1\n\n";
            return true;
        }
        else if(stack_top[sn] == 0)
        {
            cout << "Stack Number " << sn << " is Empty\n";
            return true;
        }
        else
        {
            return false;
        }
    }
};


/*
k = 3;
sn = 2
capacity = 9;
size = 9 / 3; // 3
items[(stack_number * size) + stack_top[stack_number]]
*/