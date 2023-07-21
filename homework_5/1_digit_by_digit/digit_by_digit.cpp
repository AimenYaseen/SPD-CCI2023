using namespace std;

#include <iostream>


void print_left_to_right(int num) // 123, 12, 1
{
    if(num == 0)  // base case
    { 
        return;
    }

    print_left_to_right(num / 10); // pop from stack - last in first out
    cout << num % 10 << " "; // 1 2 3
}


void print_right_to_left(int num) // 123, 12, 1
{
    if(num == 0) // base case
    {
        return;
    }

    cout << num % 10 << " ";  // 3 2 1
    print_right_to_left(num / 10);  // pop from stack
}


void print_both_sides(int num){
    if(num == 0)
    {
        return;
    }

    cout << num % 10 << " "; // right to left

    print_both_sides(num / 10);
    
    cout << num % 10 << " "; // left to right
}


int main(){
    cout << "---------- PRINT LEFT TO RIGHT --------------";
    print_left_to_right(123);  // 1 2 3
    cout << endl;

    cout << "---------- PRINT RIGHT TO LEFT --------------";
    print_right_to_left(123);  // 3 2 1
    cout << endl;

    cout << "---------- PRINT IN BOTH DIRECTIONS --------------";
    print_both_sides(123);
    cout << endl;
}