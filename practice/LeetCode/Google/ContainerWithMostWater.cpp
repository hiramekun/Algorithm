class Solution {
public:
    int maxArea(vector<int>& height) {
		int n = height.size();

		int ans = 0, l = 0, r = n - 1;
		while (l < r) {
			ans = max(min(height[l], height[r]) * (r - l), ans);
			if (height[l] < height[r]) l++;
			else r--;
		}
		return ans;
    }
};
