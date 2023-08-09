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
    int recMinDepth(TreeNode* root)
    {
        if(!root) return 0;

        // if there left tree doesn't exist then return minimum depth of right tree
        if(!root->left) return recMinDepth(root->right) + 1;
        if(!root -> right) return recMinDepth(root->left) + 1;

        return min(recMinDepth(root->left), recMinDepth(root->right)) + 1;
    }

    int minDepth(TreeNode* root) {
        return recMinDepth(root);
    }
};