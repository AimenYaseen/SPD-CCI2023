using namespace std;

#include <algorithm>
#include <vector>
#include <queue>

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
    int treeHeight(TreeNode* root)
    {
        if(!root) return 0;

        return max(treeHeight(root -> left), treeHeight(root -> right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left_height = treeHeight(root -> left);
        int right_height = treeHeight(root -> right);

        if(abs(left_height - right_height) > 1)
            return false;

        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};