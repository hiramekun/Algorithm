class Solution {
	private:
		vector<vector<int>> ans;

	public:
		void dfs(vector<int>& res, vector<int>& nums, vector<bool>& used) {
			int n = nums.size();
			if (res.size() == n) ans.emplace_back(res);

			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					used[i] = true;
					res.emplace_back(nums[i]);
					dfs(res, nums, used);
					used[i] = false;
					res.pop_back();
				}
			}
		}

		vector<vector<int>> permute(vector<int>& nums){
			vector<int> res;
			vector<bool> used(nums.size(), false);
			dfs(res, nums, used);
			return ans;
		}
};
