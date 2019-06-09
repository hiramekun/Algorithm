class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ret;
		int n = intervals.size();
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

		for (int i = 0; i < n; i++) {
			int s = intervals[i][0], e = intervals[i][1];
			while(i + 1 < n) {
				int n_s = intervals[i + 1][0], n_e = intervals[i + 1][1];
				if (n_s <= s) {
					if (s <= n_e) {
						s = n_s, e = max(n_e, e);
						i++;
						continue;
					}
				} else {
					if (n_s <= e) {
						e = max(n_e, e);
						i++;
						continue;
					}
				}
				break;
			}
			ret.emplace_back(vector<int>{s, e});
		}
		return ret;
    }
};
