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
    void BST(TreeNode*& root, vector<int> nums, int start, int end)
    {
        if(start > end) return;

        int mid = (start + end) / 2;
        root = new TreeNode(nums[mid]);
        BST(root-> left, nums, start, mid - 1);
        BST(root-> right, nums, mid + 1, end);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        BST(root, nums, 0, nums.size()-1);
        return root;
    }
};
