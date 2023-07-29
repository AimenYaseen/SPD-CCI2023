/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.
*/

using namespace std;

// Definition for singly-linked list.
struct ListNode 
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;

        // create a dummy node to avoid extra check for head node
        ListNode* dummy = new ListNode();
        ListNode* pointer = dummy;

        // iterate until l1, l2 or carry is not empty
        while(l1 || l2 || carry) 
        {
            sum = carry; // we are calculating individual nodes sum so always initialize it

            // add nodes values of l1 or l2 to carry if they exist
            if(l1) 
            {
                sum += l1-> val;
                l1 = l1 -> next;
            }
            if(l2)
            {
                sum += l2-> val;
                l2 = l2 -> next;
            }

            // let sum = 12 => 12%10 = 2 => store it in node
            // 12/10 = 1 => it will be the next carry
            int remainder = sum % 10; 
            carry = sum / 10;

            ListNode* newNode = new ListNode(remainder);
            pointer = pointer -> next = newNode;
        }

        return dummy -> next;
    }
};
