// Definition for a binary tree node.

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    void sumNumbersRec(TreeNode* root, int num, int &sum)
    {
        if(!root) return;
        if(!root -> left && !root -> right)
        {
            // if i is a leaf node; sum the number
            sum += (num * 10) + root -> val;
            return;
        }

        // pre order traversal
        num = (num * 10) + root -> val;
        sumNumbersRec(root -> left, num, sum);
        sumNumbersRec(root -> right, num, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNumbersRec(root, 0, sum);
        return sum;
    }
};