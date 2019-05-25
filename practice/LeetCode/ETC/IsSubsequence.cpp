class Solution {
	public:
		bool isSubsequence(string s, string t) {
			if (t.empty() && !s.empty()) return false;
			int n = s.size();
			int m = t.size();

			vector<vector<int>> idxs(26);
			for (int i = 0; i < m; i++) {
				idxs[t[i] - 'a'].emplace_back(i);
			}

			int cur = -1;
			for (int i = 0; i < n; i++) {
				auto ub = upper_bound(idxs[s[i] - 'a'].begin(), idxs[s[i] - 'a'].end(), cur);
				if (ub == idxs[s[i] - 'a'].end()) return false;
				cur = *ub;
			}
			return true;
		}
};
