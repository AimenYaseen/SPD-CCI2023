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
    void InOrderTraversal(TreeNode* root, int& sum)
    {
        if(!root) return;

        InOrderTraversal(root->left, sum);

        TreeNode* left_node = root -> left;
        if(left_node && !left_node -> left && !left_node -> right)
            sum += left_node -> val;

        InOrderTraversal(root->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root -> left && !root -> right) return 0;
        
        int sum = 0;
        InOrderTraversal(root, sum);

        return sum;
    }
};