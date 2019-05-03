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
public:
    bool dfs(TreeNode* node, long long r_pre, long long l_pre) {
        if (node == NULL) return false;
        if (node->left != NULL) {
            long long left_val = node->left->val;
            if (left_val < node->val && left_val > r_pre) {
                if (dfs(node->left, r_pre, node->val)) return true;
            }
            else return true;
        }
        if (node->right != NULL) {
            long long right_val = node->right->val;
            if (right_val > node->val && right_val < l_pre) {
                if (dfs(node->right, node->val, l_pre)) return true;
            }
            else return true;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return !dfs(root, -(1LL<<60), 1LL<<60);
    }
};
