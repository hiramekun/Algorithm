class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			int n = nums.size();

			const int inf = 1<<30;
			int ans = inf;
			int r = 0;
			int res = 0;
			for (int l = 0; l < n; l++) {
				while (r < n && res < s) {
					res += nums[r];
					r++;
				}
				if (res >= s) ans = min(ans, r - l);

				res -= nums[l];
				if (l == r) r++;
			}
			return ans == inf ? 0 : ans;
		}
};
