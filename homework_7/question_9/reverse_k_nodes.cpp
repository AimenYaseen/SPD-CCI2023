// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* getKthNode(ListNode* current, int k)
    {
        // move the current kth times and return current
        while(current && k>0)
        {
            current = current -> next;
            k--;
        }
        return current;
    }

    ListNode* reverseNodes(ListNode* current)
    {
        // reverse nodes
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        // dummy node
        ListNode* dummy = new ListNode();
        dummy -> next = head;

        // prev and next pointer of k group
        ListNode* PrevNode = dummy;
        ListNode* NextNode;

        // get the kth node
        ListNode* kNode = getKthNode(PrevNode, k);

        while(kNode)
        {
            // get kGroup next node
            NextNode = kNode->next;
            kNode -> next = nullptr; // break the connection to reverse it

            ListNode* reversedNodes = reverseNodes(PrevNode->next);

            PrevNode -> next = reversedNodes; // attach the reverse k nodes with previous

            while(reversedNodes -> next)
                reversedNodes = reversedNodes -> next;
            
            reversedNodes -> next = NextNode; // attach the reversed k nodes to the next nodes
            PrevNode = reversedNodes; // update previous
            kNode = getKthNode(PrevNode, k); // again get kth node
        }

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
    sol.reverseKGroup(head, 2);
}
