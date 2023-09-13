/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by 
splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one or both lists are empty
        if(!list1) return list2;
        if(!list2) return list1;

        // create a dummy node to avoid extra check for head node
        ListNode* mList = new ListNode();
        ListNode* pointer = mList;

        // if any list is empty, break. because we can't compare its value
        while(list1 && list2) 
        {
            if(list1->val < list2->val) // if list1 element is smaller place it in merge list
            {
                ListNode* temp = new ListNode(list1->val);
                pointer -> next = temp;
                list1 = list1 -> next;
            }
            else // else place list2 element
            {
                ListNode* temp = new ListNode(list2->val);
                pointer -> next = temp;
                list2 = list2 -> next;
            }
            pointer = pointer -> next;
        }

        // append the remaining nodes
        if(list1) pointer -> next = list1; 
        if(list2) pointer -> next = list2;

        return mList -> next;

    }
};