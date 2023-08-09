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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        if(!root -> left && !root -> right) return {{root->val}};

        bool rtl = false;

        queue<TreeNode*> levels;
        vector<vector<int>> nodes;

        levels.push(root);
        levels.push(nullptr);

        vector<int> level_nodes;

        while(!levels.empty())
        {
            TreeNode* node = levels.front();
            levels.pop();

            if(node == nullptr)
            {
                if(rtl) reverse(level_nodes.begin(), level_nodes.end());
                rtl = !rtl;

                nodes.push_back(level_nodes);
                level_nodes.clear();

                if(!levels.empty()) levels.push(nullptr);
            }
            else
            {
                level_nodes.push_back(node -> val);
                if(node -> left) levels.push(node -> left);
                if(node -> right) levels.push(node -> right);
            }
        }

        return nodes;
    }
};
