class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
		vector<int> ans;
		int n = input.size();

		for (int i = 0; i < n; i++) {
			char cur = input[i];
			if (cur == '*' || cur == '+' || cur == '-') {
				vector<int> left = diffWaysToCompute(input.substr(0, i));
				vector<int> right = diffWaysToCompute(input.substr(i + 1));

				for (auto e1: left) {
					for (auto e2: right) {
						if (cur == '*') {
							ans.push_back(e1 * e2);
						} else if (cur == '+') {
							ans.push_back(e1 + e2);
						} else {
							ans.push_back(e1 - e2);
						}
					}
				}
			}
		}
		if (ans.empty()) ans.push_back(stoi(input));

		return ans;
    }
};
