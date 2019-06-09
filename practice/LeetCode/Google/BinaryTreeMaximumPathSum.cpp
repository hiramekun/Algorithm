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
		int val = node->val;
		int left = max(0, maxGain(node->left));
		int right = max(0, maxGain(node->right));

		ans = max(ans, val + left + right);

		return val + max(left, right);
	}

    int maxPathSum(TreeNode* root) {
		maxGain(root);
		return ans;
    }
};
