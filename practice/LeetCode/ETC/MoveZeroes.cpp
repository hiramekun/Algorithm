class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			int n = nums.size();
			for (int i = n - 2; i >= 0; i--) {
				if (nums[i] == 0) {
					for (int j = i; j < n - 1; j++) {
						if (nums[j + 1] != 0) swap(nums[j], nums[j + 1]);
						else break;
					}
				}
			}
		}
};
