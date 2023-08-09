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
    // in order traversal to calculate tree nodes frequency
    void InOrderTraversal(TreeNode* root, unordered_map<int, int>& value_count)
    {
        if(!root) return;

        InOrderTraversal(root->left, value_count);
        value_count[root -> val]++;
        InOrderTraversal(root->right, value_count);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> value_count;

        InOrderTraversal(root, value_count);

        // find maximum frequency in tree
        int max_frequency = 0;
        for(const auto& pair: value_count)
            max_frequency = max(max_frequency, pair.second);

        // filter out nodes with maximum frequency
        vector<int> modes;
        for(const auto& pair: value_count)
        {
            if(pair.second == max_frequency)
                modes.push_back(pair.first);
        }

        return modes;
    }
};