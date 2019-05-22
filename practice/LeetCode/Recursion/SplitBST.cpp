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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
		vector<TreeNode*> ret(2, NULL);
		if (root == NULL) return ret; 
		if (root->val <= V) {
			ret[0] = root;
			vector<TreeNode*> res = splitBST(root->right, V);
			root->right = res[0];
			ret[1] = res[1];
		} else {
			ret[1] = root;
			vector<TreeNode*> res = splitBST(root->left, V);
			root->left = res[1];
			ret[0] = res[0];
		}
		return ret;
    }
};
