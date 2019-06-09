class Solution {
public:
    string decodeString(string& s, int& i) {
		string ret;

		while (i < s.size() && s[i] != ']') {
			if (!isdigit(s[i])) {
				ret += s[i];
				i++;
			} else {
				int num = 0;
				while (i < s.size() && isdigit(s[i])) num = num * 10 + s[i++] - '0';
				i++; // skip [
				string temp = decodeString(s, i);
				i++; // skip ]
				while (num--) ret += temp;
			}
		}

		return ret;
    }

	string decodeString(string s) {
		int i = 0;
		return decodeString(s, i);
	}
};
