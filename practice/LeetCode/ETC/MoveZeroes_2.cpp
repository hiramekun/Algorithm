class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			int n = nums.size();
			int last_nonzero = 0;
			for (int i = 0; i < n; i++) {
				if (nums[i] != 0) nums[last_nonzero++] = nums[i];
			}
			for (int i = last_nonzero; i < n; i++) nums[i] = 0;
		}
};
