class Solution {
	public:
		int find(int s, int e, vector<int>& v, int target) {
			if (v.empty()) return -1;
			int mid = (s + e) / 2;
			if (v[mid] == target) return mid;
			if (s >= e) return -1;

			if (v[s] < v[e]) {
				if (v[mid] > target) e = mid;
				else s = mid + 1;
				int val = find(s, e, v, target);
				if (val != -1) return val;
			} else {
				if (v[s] <= v[mid]) {
					if (v[s] <= target && target <= v[mid]) {
						e = mid;
					} else {
						s = mid + 1;
					}
				} else if (v[e] > v[mid]){
					if (v[mid] <= target && target <= v[e]) {
						s = mid + 1;
					} else{
						e = mid;
					}
				}
				int val = find(s, e, v, target);
				if (val != -1) return val;
			}
			return -1;
		}

		int search(vector<int>& nums, int target) {
			return find(0, nums.size() - 1, nums, target);
		}
};
