class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		int n = equations.size();
		vector<double> ans;
		unordered_map<string, unordered_map<string, double>> mp;

		for (int i = 0; i < n; i++) {
			mp[equations[i][0]][equations[i][1]] = values[i];
			mp[equations[i][1]][equations[i][0]] = 1 / values[i];
		}

		int m = queries.size();
		for (int i = 0; i < m; i++) {
			string child = queries[i][0];
			string moth = queries[i][1];
			
		}

		return ans;
    }
};
