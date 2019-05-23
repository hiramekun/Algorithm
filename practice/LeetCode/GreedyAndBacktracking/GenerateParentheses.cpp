class Solution {
	public:
		vector<string> ans;
		void dfs(string& now, int n, int sum) {
			if (now.size() == n * 2) {
				if (sum == 0) ans.emplace_back(now);
				return;
			}
			if (sum < 0) return;
			now += "(";
			dfs(now, n, sum + 1);
			now.pop_back();

			now += ")";
			dfs(now, n, sum - 1);
			now.pop_back();
		}

		vector<string> generateParenthesis(int n) {
			string now = "";
			dfs(now, n, 0);
			return ans;
		}
};
