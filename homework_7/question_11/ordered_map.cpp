using namespace std;

#include <map>

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
    ListNode* deleteDuplicates(ListNode* head) {
        // if list is empty
        if(!head) return nullptr;

        map<int, int> listValues; // ordered map to store values against values

        for(ListNode* it=head; it; it=it->next)
        {
            // iterate through list and store unique elements in map
            if(listValues.find(it->val) == listValues.end())
                listValues[it->val] = it->val;
        }

        // create a dummy node to avoid extra check for head node
        ListNode* dummy = new ListNode();
        ListNode* it = dummy;

        for(auto value : listValues)
        {
            // do insertAtHead because map returns elements in order
            ListNode* node = new ListNode(value.first);
            it = it -> next = node;
        }

        return dummy -> next;
    }
};