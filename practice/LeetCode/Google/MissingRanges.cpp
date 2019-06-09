class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		if (nums.empty()) {
			if (lower == upper) return vector<string>{to_string(lower)};
			else return vector<string>{to_string(lower)  + "->" + to_string(upper)};
		}
		int now = lower;
		int n = nums.size();

		vector<string> ans;
		for (int i = 0; i < n; i++) {
			if (now == nums[i] && now < INT_MAX) now++;
			else if (now < nums[i]){
				string tmp;
				if (now == nums[i] - 1) tmp = to_string(now);
				else tmp = to_string(now)  + "->" + to_string(nums[i] - 1);
				ans.emplace_back(tmp);
				if (nums[i] < INT_MAX) now = nums[i] + 1;
				else now = INT_MAX;
			}
		}
		if (now == upper && nums.back() != upper) ans.emplace_back(to_string(upper));
		else if (now < upper) ans.emplace_back(to_string(now) + "->" + to_string(upper));
		return ans;
    }
};
