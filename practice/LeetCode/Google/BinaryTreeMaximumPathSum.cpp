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
	int ans = INT_MIN;
	int maxGain(TreeNode* node) {
		if (node == NULL) return 0;
		int left = max(maxGain(node->left), 0);
		int right = max(maxGain(node->right), 0);

		int tmp = node->val + left + right;
		ans = max(tmp, ans);

		return node->val + max(left, right);
	}

    int maxPathSum(TreeNode* root) {
		maxGain(root);
		return ans;
    }
};
