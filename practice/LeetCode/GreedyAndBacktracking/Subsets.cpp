class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> ans;
			int n = nums.size();

			for (int i = 0; i < 1 << n; i++) {
				vector<int> tmp;
				for (int j = 0; j < n; j++) {
					if (i & (1 << j)) {
						tmp.emplace_back(nums[j]);
					}
				}
				ans.emplace_back(tmp);
			}
			return ans;
		}
};
