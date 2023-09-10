/*
Problem 1: Three in one
Description: Describe how you could use a single array to implement three stacks?
*/

using namespace std;

#include <iostream>
#include "three_in_one.h"


int main(){
    ThreeStacks three_stacks(9, 3);

    three_stacks.push(1, 3);
    three_stacks.top(1); // 3

    three_stacks.push(0, 5);
    three_stacks.push(2, 8);

    three_stacks.push(1, 9);
    three_stacks.push(1, 4);
    three_stacks.top(1); // 4

    three_stacks.push(1, 9); // overflow

    three_stacks.top(0); // 5
    three_stacks.pop(0);
    three_stacks.pop(0); // underflow

    three_stacks.pop(1); // 4
}