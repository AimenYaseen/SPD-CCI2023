// https://leetcode.com/problems/merge-k-sorted-lists/

using namespace std;

#include <vector>

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

    ListNode* mergeLists(ListNode* l1, ListNode* l2)
    {
        // same code as merge two sorted lists
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ListNode* node = new ListNode(l1->val);
                tail -> next = node;
                l1 = l1 -> next;
            }
            else
            {
                ListNode* node = new ListNode(l2->val);
                tail -> next = node;
                l2 = l2 -> next;
            }
            tail = tail -> next;
        }

        if(l1) tail -> next = l1;
        if(l2) tail -> next = l2;

        return dummy -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if lists is empty
        if(lists.size()==0) return nullptr;
        
        // loop until all the list merged to one
        while(lists.size() > 1)
        {
            vector<ListNode*> _lists; // store merged lists
            for(int i=0; i < lists.size(); i=i+2) // jump two times as we are merging two lists
            {
                ListNode* list1 = lists[i], *list2 = nullptr; // list2 will be null in last iteration in case of odd numbers

                if(i+1<lists.size()) list2 = lists[i+1];

                _lists.push_back(mergeLists(list1, list2)); 
            }
            lists = _lists; // update lists by new merged lists
        }

        return lists[0];
    }
};