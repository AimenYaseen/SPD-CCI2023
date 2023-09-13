// https://leetcode.com/problems/partition-list/

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // if list is empty
        if(!head) return head;

        // dummy nodes
        ListNode* smaller_dummy = new ListNode();  // list contains values smaller than x
        ListNode* greater_dummy = new ListNode(); // list contains values greater than or equal to x

        ListNode* p1=smaller_dummy, *p2=greater_dummy; // list pointers

        while(head)
        {
            // create a node with head value
            ListNode* node = new ListNode(head -> val);

            // store values according to less or greater condition
            if(head -> val < x) p1 = p1 -> next = node;
            else p2 = p2 -> next = node;

            head = head -> next; // move head
        }

        // attach 2nd list with smaller list
        p1 -> next = greater_dummy -> next;
        return smaller_dummy -> next; // return smaller list head
    }
};