/*
Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.
*/

using namespace std;

#include <cmath>


// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int count = 0;
        // let list has 101; it will be calculated like
        for(ListNode* i=head; i!=nullptr; i=i->next)
        {
            count++; // calculate list count; 3
        }
        
        int result = 0;  // 1*2^2 + 0*2^1 + 1*2^0 = 5

        for(ListNode* i=head; i!=nullptr; i=i->next)
        {
            result += (i->val * pow(2, count - 1));
            count--;
        }

        return result;
    }
};