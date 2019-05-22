class Solution {
	public:
		int shipWithinDays(vector<int>& weights, int D) {
			int n = weights.size(); 
			int max_w = *max_element(weights.begin(), weights.end());

			int s = -1, e = max_w * n;
			while (abs(e - s) > 1) {
				int mid = (e + s) / 2;
				int devide = 1;
				int temp = 0;
				for (int i = 0; i < n; i++) {
					if (temp + weights[i] <= mid) {
						temp += weights[i];
					} else {
						temp = weights[i];
						if (temp > mid) {
							devide = 1e9;
							break;
						}
						devide++;
					}
				}
				if (devide > D) s = mid;
				else e = mid;
			}
			return e;
		}
};
