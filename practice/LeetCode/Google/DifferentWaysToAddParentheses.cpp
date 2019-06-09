class Solution {
	public:
		vector<int> diffWaysToCompute(string input) {
			vector<int> ans;
			int n = input.size();

			for (int i = 0; i < n; i++) {
				char cur = input[i];
				if (cur == '+' || cur == '-' || cur == '*') {
					vector<int> result1 = diffWaysToCompute(input.substr(0, i));
					vector<int> result2 = diffWaysToCompute(input.substr(i + 1));

					for (auto n1: result1) {
						for (auto n2: result2) {
							if (cur == '+') ans.push_back(n1 + n2);
							else if (cur == '-') ans.push_back(n1 - n2);
							else ans.push_back(n1 * n2);
						}
					}
				}
			}
			if (ans.empty()) ans.push_back(stoi(input));
			return ans;
		}
};
