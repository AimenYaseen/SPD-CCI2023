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
    bool compareLeftRight(TreeNode* p, TreeNode* q)
    {
        if(!p & !q) return true;
        if(!p || !q) return false;

        if(p -> val != q -> val)
            return false;

        return compareLeftRight(p -> left, q -> right) && compareLeftRight(p -> right, q -> left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!root -> left && !root -> right) return true;

        return compareLeftRight(root -> left, root -> right);
    }
};