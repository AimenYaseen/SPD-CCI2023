using namespace std;

//  Definition for singly-linked list.
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
        {
            count++;
        }
        
        // create a dummy node to avoid extra code for head
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* prev = dummy;  // previous of the delete node
        int k = count - n; // position of the delete node
        
        for(int i=0; i < k; i++)
            prev = prev -> next;

        // update pointers and delete the nth node
        ListNode* deleteNode = prev -> next;
        prev -> next = deleteNode -> next;
        delete deleteNode;

        return dummy -> next; // return the head
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

    ListNode* head2 = new ListNode(1);
    sol.removeNthFromEnd(head2, 1);
}
