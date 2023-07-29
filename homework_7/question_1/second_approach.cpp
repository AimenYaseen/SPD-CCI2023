using namespace std;

// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int getDecimalValue(ListNode* head) {

        int result = 0;
        ListNode* pointer = head;

        while(pointer)
        {
            // shifting by 1 means multiplying by 2
            // here we are just placing bits in 32 bit result after shifting by 1
            // In memeory results are stored in 0, 1 form
            // So, it will place 101 in memory which will be 5 when we print it.
            result = (result << 1) + (pointer -> val); 
            pointer = pointer -> next;
        }

        return result;
    }
};