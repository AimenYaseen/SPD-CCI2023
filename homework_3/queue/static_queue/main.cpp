/*
Problem 1: Three in one
Description: Describe how you could use a single array to implement three stacks?
*/

using namespace std;

#include <iostream>
#include "static_queue.h"


int main(){
    StaticQueue static_queue(4);

    static_queue.enQueue(3);
    static_queue.rear_top(); // 3

    static_queue.enQueue(5);
    static_queue.enQueue(8);

    static_queue.enQueue(9);
    static_queue.enQueue(4); // full

    static_queue.rear_top(); // 9
    static_queue.front_top(); // 3

    static_queue.deQueue();
    static_queue.front_top(); // 5

    static_queue.deQueue();
    static_queue.deQueue(); 

    static_queue.front_top(); // 9
    static_queue.deQueue(); 
    static_queue.front_top(); // 0
}