// https://leetcode.com/problems/reverse-linked-list-ii/

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

    ListNode* reverseLinkedlist(ListNode* current)
    {
        ListNode* prev = nullptr;
        ListNode* next;

        while(current)
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if there is only one node
        if(left == 1 && right == 1) return head;

        // create a dummy node 
        ListNode* dummy = new ListNode();
        dummy -> next = head;

        //initialize all pointers
        ListNode *pointer = dummy, *leftP, *rightP, *leftPrev, *rightNext; 

        // find left pointer
        for(int i=0; i<left; i++)
        {
            leftPrev = pointer;
            pointer = pointer -> next;
        }
        leftP = pointer;

        // find right pointer
        while(left<right)
        {
            pointer = pointer -> next;
            left++;
        }
        rightP = pointer;
        rightNext = rightP -> next;
        rightP -> next = nullptr; // set next of right pointer to null to break the connection

        ListNode* reverse = reverseLinkedlist(leftP); // reverse linked list
        leftPrev -> next = reverse; // attach reverse linked list with left previous

        // find the end of reverse list
        while(reverse->next)
            reverse = reverse -> next;

        // attach reverse end with the right next pointer
        reverse -> next = rightNext;

        // return head
        return dummy -> next;
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
    sol.reverseBetween(head, 1, 5);
}