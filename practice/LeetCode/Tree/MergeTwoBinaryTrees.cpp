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
    TreeNode* merge(TreeNode* t1, TreeNode* t2, TreeNode* ret) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        } else if (t1 == NULL) {
            ret = new TreeNode(t2->val);
            ret->left = merge(t2->left, NULL, ret->left);
            ret->right = merge(t2->right, NULL, ret->right);
        } else if (t2 == NULL) {
            ret = new TreeNode(t1->val);
            ret->left = merge(t1->left, NULL, ret->left);
            ret->right = merge(t1->right, NULL, ret->right);
        } else {
            ret = new TreeNode(t1->val + t2->val);
            ret->left = merge(t1->left, t2->left, ret->left);
            ret->right = merge(t1->right, t2->right, ret->right);
        }
        return ret;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* ret = NULL;
        ret = merge(t1, t2, ret);
        return ret;
    }
};
