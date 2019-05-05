class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;
        for (string s: emails) {
            string temp;
            bool ignore = false;
            bool go_to_domain = false;
            for (int i = 0; i <= s.size(); i++) {
                if (s[i] == '@') {
                    ignore = true;
                    go_to_domain = false;
                }
                if (go_to_domain) continue;
                if (s[i] == '+' && !ignore) {
                    go_to_domain = true;
                    continue;
                }
                if (!ignore && s[i] == '.') continue;
                temp += s[i];
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};
