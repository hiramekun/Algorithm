class Solution {
public:
    string decodeString(string& s, int& i) {
		int n = s.size();
		string ans;

		while(i < n && s[i] != ']') {
			if (!isdigit(s[i])) {
				ans += s[i];
				i++;
			} else {
				int num = 0;
				while(i < n  && isdigit(s[i])) num = num * 10 + s[i++] - '0';
				i++;
				string t = decodeString(s, i);
				i++;
				while(num--) ans += t;
			}
		}
		return ans;
    }

	string decodeString(string s) {
		int i = 0;
		return decodeString(s, i);
	}
};
