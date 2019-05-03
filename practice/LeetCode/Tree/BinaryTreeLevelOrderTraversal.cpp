/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> ret;
public:
    void dfs(TreeNode* node, int level) {
        if (node == NULL) return;
        if (ret.size() == level) ret.emplace_back(vector<int>());
        ret[level].emplace_back(node->val);
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
};
