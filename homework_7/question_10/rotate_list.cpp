// Rotate List: https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        // if list is empty
        if(!head) return nullptr;
        ListNode* tail; // tail of current list

        int n = 0; // list count
        for(ListNode* i=head; i; i=i->next)
        {
            tail = i;
            n++;
        } 

        // find actual rotation; eg if k = 5 while n = 2 then there should be only 1 rotation
        k = k % n; 
        if(k == 0) return head; // if k=4 and n=2 then there will be no rotation

        int pIndex = n - k; // partition index
        ListNode* pointer = head;

        for(int i=1; i < pIndex; i++)
            pointer = pointer -> next;

        ListNode* rotateStart = pointer -> next; // cut at the rotation point
        pointer -> next = nullptr; // convert it to tail

        tail -> next = head; // point tail to head
        head = rotateStart; // update head
        return head;        
    }
};