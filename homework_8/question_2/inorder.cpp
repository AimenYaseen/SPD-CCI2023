using namespace std;

#include <vector>

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
    void LNR(TreeNode* root, vector<int> &lnr)
    {
        if(!root) return;
        
        LNR(root->left, lnr);
        lnr.push_back(root -> val);
        LNR(root->right, lnr);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // base cases
        if (!root) return {};  // if tree does not exist
        if(!root->left && !root->right) return {root -> val};  // if only root is present

        vector<int> lnr;

        LNR(root, lnr);
        return lnr;
    }
};