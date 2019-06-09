class Solution {
public:
    string removeDuplicates(string S) {
		stack<char> stack1;
		int n = S.size();
		string ans;
		for (int i = 0; i < n; i++) {
			if (ans.empty() || ans.back() != S[i]) ans += S[i];
			else ans.pop();
		}
		return ans;
    }
};
