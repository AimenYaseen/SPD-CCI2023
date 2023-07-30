// https://leetcode.com/problems/palindrome-linked-list/

using namespace std;

#include <unordered_map>

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
        // if there is only one node to reverse
        if(!current->next) return current;

        // 1->2->3
        ListNode* prev = nullptr;
        ListNode* next;

        while(current) // 1 ; 2; 3
        {
            next = current -> next; // 2; 3; nullptr
            current -> next = prev; // nullptr; 1; 2
            prev = current; // 1; 2; 3 
            current = next; // 2; 3; nullptr
        } // nullptr<-1 2->3;  // nullptr<-1<-2->3; // nullptr<-1<-2<-3

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head -> next) return true; // if there is only one node

        ListNode *fast = head, *slow = head;

        while(fast->next && fast->next->next)
        {
            // move fast two times and slow one time until fast->next and fast->next->next
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        // reverse linked list from the next of slow
        ListNode* reverse = reverseLinkedlist(slow->next);

        // compare the first half and reverse half 
        while(head && reverse)
        {
            if(head -> val != reverse -> val)
                return false;

            head = head -> next;
            reverse = reverse -> next;
        }
        return true;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    t = t -> next = new ListNode(0);
    t = t -> next = new ListNode(0);

    Solution sol;
    sol.isPalindrome(head);
}
