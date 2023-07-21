using namespace std;

#include <iostream>


void print_left_to_right(int num)
{
    if(num == 0){
        return;
    }

    print_left_to_right(num / 10);
    cout << num % 10 << " ";
}


void print_right_to_left(int num)
{
    if(num == 0){
        return;
    }

    cout << num % 10 << " ";
    print_right_to_left(num / 10);
}


int main(){
    cout << "---------- PRINT LEFT TO RIGHT --------------";
    print_left_to_right(123);  // 1 2 3
    cout << endl;

    cout << "---------- PRINT RIGHT TO LEFT --------------";
    print_right_to_left(123);  // 3 2 1
    cout << endl;
}