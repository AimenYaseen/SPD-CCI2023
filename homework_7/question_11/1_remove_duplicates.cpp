// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        // if list is empty
        if(!head) return nullptr;

        unordered_map<int, int> listValues; // map to store values against values

        for(ListNode* it=head; it; it=it->next)
        {
            // iterate through list and store unique elements in map
            if(listValues.find(it->val) == listValues.end())
                listValues[it->val] = it->val;
        }

        // create head node using map's first element
        auto map = listValues.begin();
        ListNode* _head = new ListNode(map->first);
        ++map; // move map to the next element

        for(; map != listValues.end(); ++map)
        {
            // do insertAtTail because map returns the last inserted element first
            ListNode* node = new ListNode(map->first, _head);
            _head = node;
        }

        return _head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    t = t -> next = new ListNode(1);
    t = t -> next = new ListNode(2);

    Solution sol;
    sol.deleteDuplicates(head);
}

/*
Problem with this Solution:
It returns values in unsorted order as I am using unordered map.
*/