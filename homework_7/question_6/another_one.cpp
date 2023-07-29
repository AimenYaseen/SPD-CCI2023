
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if there is one node in list and n == 1
        if(!head -> next && n == 1)
        {
            delete head;
            return nullptr;
        }

        // count the number of nodes
        int count = 0;
        for(ListNode* i=head; i; i=i->next)
            count++;
        
        int k = count - n; // position of the delete node

        if( k == 0) // It means we have to delete the head
        {
            ListNode* node = head;
            head = head -> next;
            delete node;
            return head;
        }

        ListNode* prev = head;  // previous of the delete node
        
        
        for(int i=1; i < k; i++)
            prev = prev -> next;

        // update pointers and delete the nth node
        ListNode* deleteNode = prev -> next;
        prev -> next = deleteNode -> next;
        delete deleteNode;

        return head; // return the head
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    t = t -> next = new ListNode(2);
    t = t -> next = new ListNode(3);
    t = t -> next = new ListNode(4);
    t = t -> next = new ListNode(5);

    Solution sol;
    sol.removeNthFromEnd(head, 2);
}