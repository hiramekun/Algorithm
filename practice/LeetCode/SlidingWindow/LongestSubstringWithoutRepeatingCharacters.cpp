class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			unordered_set<char> char_set;
			int n = s.size();

			int ans = 0;
			int r = 0;
			for (int l = 0; l < n; l++) {
				while (r < n && char_set.find(s[r]) == char_set.end()) {
					char_set.insert(s[r]);
					r++;
				}
				ans = max<int>(ans, char_set.size());
				char_set.erase(s[l]);
				if (r == n) break;
				if (l == r) r++;
			}
			return ans;
		}
};
