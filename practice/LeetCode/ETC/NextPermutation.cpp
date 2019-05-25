class Solution  {
	public:
		void nextPermutation(vector<int>&  nums) {
			int n = nums.size();
			bool swapped = false;
			for (int i = n - 1; i >= 0; i--) {
				int cur = (int)1e9;
				int swap_pos = i;
				for (int j = i + 1; j < n; j++) {
					if (nums[j] > nums[i] && nums[j] <= cur) {
						cur = nums[j];
						swap_pos = j;
						swapped = true;
					}
				}
				if (swapped) {
					swap(nums[i], nums[swap_pos]);
					break;
				}
			}
			if (!swapped) sort(nums.begin(), nums.end());
		}
};
