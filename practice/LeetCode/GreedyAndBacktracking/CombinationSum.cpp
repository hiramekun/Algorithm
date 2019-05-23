class Solution {
	public:
		vector<vector<int>> ans;
		void dfs(vector<int> ret, vector<int>& candidates, int target, int sum, int i, bool use) {
			if (i == candidates.size()) return;

			if (use) {
				sum += candidates[i];
				ret.emplace_back(candidates[i]);
			}
			if (sum == target) ans.emplace_back(ret);
			if (sum >= target) return;

			if (use) dfs(ret, candidates, target, sum, i, true);
			dfs(ret, candidates, target, sum, i + 1, true);
			dfs(ret, candidates, target, sum, i + 1, false);
		}

		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<int> ret;
			dfs(ret, candidates, target, 0, 0, true);
			dfs(ret, candidates, target, 0, 0, false);
			return ans;
		}
};
