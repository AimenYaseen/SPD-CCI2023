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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &pre, int i, int j)
    {
        if(i > j) return nullptr;
        
        // root node from preorder
        int root_val = preorder[pre];
        TreeNode* root = new TreeNode(root_val);
        pre++; 

        // find root in inorder in range i to j
        int mid;
        for(int temp=i; i<=j; temp++)
        {
            if(root_val == inorder[temp])
            {
                mid = temp;
                break;
            }
        }

        // left side values will be the root left & vice versa
        root -> left = build(preorder, inorder, pre, i, mid - 1);
        root -> right = build(preorder, inorder, pre, mid + 1, j);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // index will point to preorder vector
        int index = 0; 
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
};
