class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int n = nums.size();
			int s = -1, e = n;
			while (e - s > 1) {
				int mid = (s + e) / 2;
				if (nums[mid] == target) return mid;
				if (nums[mid] > target) e = mid;
				else s = mid;
			}
			return e;
		}
};
