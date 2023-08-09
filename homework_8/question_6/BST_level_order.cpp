using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        if(!root -> left && !root -> right) return {{root -> val}};
        
        queue<TreeNode*> levels;
        vector<vector<int>> nodes;

        levels.push(root);
        levels.push(nullptr);

        while(!levels.empty())
        {
            vector<int> level_nodes;

            while(levels.front() != nullptr)
            {
                TreeNode* level = levels.front();
                levels.pop();

                level_nodes.push_back(level -> val);
                if(level -> left) levels.push(level -> left);
                if(level -> right) levels.push(level -> right);
            }
            levels.pop();

            if(!levels.empty()) 
                levels.push(nullptr);
                
            nodes.push_back(level_nodes);
        }

        return nodes;
    }

};