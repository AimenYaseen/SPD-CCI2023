
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
        // if there is only one node
        if(!head->next && n == 1)
        {
            delete head;
            return nullptr;
        }

        ListNode* f = head; // fast pointer
        ListNode* s = head; // slow pointer

        // move fast pointer n times
        while(n--)
            f = f -> next;

        // if fast pointer is null then it means we have to remove the first node
        if(!f)
        {
            ListNode* node = head;
            head = head -> next;
            delete node;
            return head;
        }

        // move start pointer until fast pointer next becomes null
        while(f -> next)
        {
            s = s -> next;
            f = f -> next;
        }

        // start pointer represents previous node of delete node
        ListNode* deleteNode = s -> next;
        s -> next = deleteNode -> next;
        delete deleteNode;
        return head;
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