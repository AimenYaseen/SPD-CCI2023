using namespace std;

#include <limits.h>
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        vector<int> max_values;
        queue<TreeNode*> levels;

        levels.push(root);
        levels.push(nullptr);

        while(!levels.empty())
        {
            int max = INT_MIN; // Initialize max with the smallest possible integer value

            while(levels.front())
            {
                TreeNode* node = levels.front();
                levels.pop();

                if(node -> val > max) max = node -> val;

                if(node -> left) levels.push(node -> left);
                if(node -> right) levels.push(node -> right);
            }
            levels.pop();
            if(!levels.empty()) levels.push(nullptr);

            max_values.push_back(max);
        }
        return max_values;

    }
};