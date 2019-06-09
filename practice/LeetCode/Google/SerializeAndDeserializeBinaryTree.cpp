/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	vector<string> split(const string &str, char sep) {
		vector<string> v;
		stringstream ss(str);
		string buffer;
		while(getline(ss, buffer, sep) ) {
			v.push_back(buffer);
		}
		return v;
	}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		if (root == NULL) return "NULL,";
		string left = serialize(root->left);
		string right = serialize(root->right);
		
		return to_string(root->val) + "," + left + right;
    }

	TreeNode* deserialize(deque<string> &que) {
		string value = que.front();
		que.pop_front();
		if (value == "NULL") return NULL;

		TreeNode* node = new TreeNode(stoi(value));
		node->left = deserialize(que);
		node->right = deserialize(que);
		return node;
	}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		vector<string> v = split(data, ',');
		deque<string> que(v.begin(), v.end());
		return deserialize(que);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
