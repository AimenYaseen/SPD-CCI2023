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
    void pathSum(TreeNode* root, int targetSum, vector<int> single_path, vector<vector<int>> &paths)
    {
        if(!root) return;

        single_path.push_back(root -> val);
        
        // leaf node
        if(!root -> left && !root -> right)
        {
            if(targetSum == root -> val)
                paths.push_back(single_path);
        }

        pathSum(root -> left, targetSum - root -> val, single_path, paths);
        pathSum(root -> right, targetSum - root -> val, single_path, paths);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> single_path;

        pathSum(root, targetSum, single_path, paths);
        return paths;
    }
};
