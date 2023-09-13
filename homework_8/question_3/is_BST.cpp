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

    bool isValidBST(TreeNode* root) {
        if(!root-> left && !root->right) return true;

        vector<int> lnr;
        LNR(root, lnr);

        for(int i=1; i<lnr.size(); i++)
        {
            if(lnr[i] <= lnr[i-1]) 
                return false;
        }

        return true;
    }
};