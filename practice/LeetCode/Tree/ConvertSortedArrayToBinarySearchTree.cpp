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
    TreeNode* dfs(TreeNode* node, vector<int>& nums, int low, int high) {
        if (low > high) return node;
        int mid = (low + high) / 2;
        node = new TreeNode(nums[mid]);
        node->left = dfs(node->left, nums, low, mid - 1);  
        node->right = dfs(node->right, nums, mid + 1, high);  
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* now = NULL;
        if (nums.empty()) return now;
        int n = nums.size(); 
        now = dfs(now, nums, 0, n - 1);
        return now;
    }
};
