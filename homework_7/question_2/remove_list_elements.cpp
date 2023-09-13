/*
Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, 
and return the new head.
*/

using namespace std;

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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head->val == val) // If head contains the removing value
        {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }

        if(!head)  // If all values equal to rem value then at this point list will be empty
            return nullptr;

        ListNode* temp = head; // non removing value
        ListNode* temp_next = temp -> next;
        while(temp_next) // because current pos does not contain the rem value so check next
        {
            if(temp_next -> val == val)
            {
                ListNode* t = temp_next;
                temp_next = temp -> next = temp_next -> next;
                delete t;
            }
            else
            {
                temp = temp_next;
                temp_next = temp_next -> next;
            }
        }

        return head;
    }
};