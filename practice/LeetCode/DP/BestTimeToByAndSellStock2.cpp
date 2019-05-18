class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int high = prices[0];
		int low = prices[0];

		int idx = 0;
		int n = prices.size();

		long long ans = 0;
		while (idx + 1 < n) {
			while (idx + 1 < n && prices[idx + 1] <= prices[idx]) idx++;
			low = prices[idx];

			while (idx + 1 < n && prices[idx + 1] >= prices[idx]) idx++;
			high = prices[idx++];

			ans += high - low;
		}
		return ans;
    }
};
