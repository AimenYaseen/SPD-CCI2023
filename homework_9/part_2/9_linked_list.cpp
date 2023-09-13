using namespace std;

#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_set>


// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        if(!head -> next) return  nullptr;

        ListNode* p = head;
        unordered_set<ListNode *> s;

        while(p)
        {
            auto it = s.find(p);
            if(it != s.end())
                return *it;

            s.insert(p);
            p = p -> next;
        }

        return nullptr;
    }
};