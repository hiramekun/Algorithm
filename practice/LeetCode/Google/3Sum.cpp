class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());

		vector<vector<int>> ans;
		int prev = INT_MAX;
		for (int i = 0; i < n - 2; i++) {
			while (i + 1 < n && nums[i] == prev) {
				i++;
				prev = nums[i];
			}
			for (int j = i + 1; j < n - 1; j++) {
				int val = 0 - nums[i] - nums[j];
				auto lb = lower_bound(nums.begin() + j + 1, nums.end(), val);
				if (lb != nums.end() && nums[i] + nums[j] + *lb == 0) {
					vector<int> tmp{nums[i], nums[j], *lb};
					ans.emplace_back(tmp);
				}
			}
			prev = nums[i];
		}

		return ans;
    }
};
