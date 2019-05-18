class Solution {
public:
	const int INVALID = -1;
	const int TRUE = 1;
	const int FALSE = 0;
    bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<int> memo(s.size(), INVALID);
		return recursion(s, wordSet, 0, memo);
    }

	int recursion(string& s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
		if (start == s.size()) return true;
		if (memo[start] != INVALID) return memo[start];

		for (int end = start; end < s.size(); end++) {
			if (wordSet.find(s.substr(start, end - start + 1)) != wordSet.end()) {
				if (recursion(s, wordSet, end + 1, memo) == TRUE) return memo[start] = TRUE;
			}
		}
		return memo[start] = FALSE;
	}
};
