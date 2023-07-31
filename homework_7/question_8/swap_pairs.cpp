// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* dummy = new ListNode();
        dummy -> next = head;

        ListNode* prev = dummy;
        ListNode* first = head;

        while(first && first->next)
        {
            // get second node
            ListNode* second = first->next;
            ListNode* next = second -> next; // get the next of second

            // reverse nodes
            second -> next = first; // reverse the pointer
            prev -> next = second; // update previous next as we reversed the connection
            first -> next = next; // update swap nodes next

            prev = first;
            first = next;
        }

        return dummy -> next;
    }
};