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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<TreeNode*> v_now, v_next;
        bool l_to_r = false;
        if (root == NULL) return ret;
        v_now.emplace_back(root);
        int depth = -1;
        while(!v_now.empty()) {
            ret.emplace_back(vector<int>());
            depth++;
            for (TreeNode* n: v_now) {
                ret[depth].emplace_back(n->val);
            }
            for (int i = v_now.size()- 1; i >= 0; i--) {
                if (l_to_r) {
                    if (v_now[i]->left != NULL) v_next.emplace_back(v_now[i]->left);
                    if (v_now[i]->right != NULL) v_next.emplace_back(v_now[i]->right);
                } else {
                    if (v_now[i]->right != NULL) v_next.emplace_back(v_now[i]->right);
                    if (v_now[i]->left != NULL) v_next.emplace_back(v_now[i]->left);
                }

            }
            v_now = v_next;
            v_next.clear();
            l_to_r = !l_to_r;
        }
        return ret;
    }
};
