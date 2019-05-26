class Solution  {
	public:
		void nextPermutation(vector<int>&  nums) {
			int n = nums.size();

			int idx = n - 1;
			while (idx > 0  && nums[idx] <= nums[idx - 1]) {
				idx--;
			}

			if (idx > 0) {
				int left = idx - 1;

				int right = left;
				while (right + 1 < n && nums[right + 1] > nums[left]) right++;
				swap(nums[left], nums[right]);
			}
			reverse(nums.begin() + idx, nums.end());
		}
};
