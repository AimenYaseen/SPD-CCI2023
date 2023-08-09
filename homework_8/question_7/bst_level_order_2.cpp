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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {{root->val}};

        queue<TreeNode*> levels;
        vector<vector<int>> nodes;

        levels.push(root);

        while(!levels.empty())
        {
            vector<int> level_nodes;
            int size = levels.size();

            for(int i=0; i<size; i++)
            {
                TreeNode* node = levels.front();
                levels.pop();

                level_nodes.push_back(node->val);
                if(node -> left) levels.push(node -> left);
                if(node -> right) levels.push(node -> right);
            }
            nodes.push_back(level_nodes);
        }
        reverse(nodes.begin(), nodes.end());
        return nodes;
    }
};
