class Solution {
	public:
		vector<vector<int>> ans;
		void dfs(vector<int>& ret, vector<int>& candidates, int target, int sum, int idx) {
			if (target == sum) ans.emplace_back(ret);
			if (sum >= target) return;

			for (int i = idx; i < candidates.size(); i++) {
				ret.emplace_back(candidates[i]);
				dfs(ret, candidates, target, sum + candidates[i], i);
				ret.pop_back();
			}
		}

		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<int> ret;
			dfs(ret, candidates, target, 0, 0);
			return ans;
		}
};
