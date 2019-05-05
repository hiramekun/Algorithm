class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> copy;
        for (int i = 0; i < strs.size(); i++) {
            copy.emplace_back(make_pair(strs[i], i));
            sort(copy[i].first.begin(), copy[i].first.end());
        }
        sort(copy.begin(), copy.end());
        vector<vector<string>> ans;
        for (int i = 0; i < copy.size(); i++) {
            vector<string> temp;
            temp.emplace_back(strs[copy[i].second]);
            while (i + 1 < copy.size() && copy[i].first == copy[i + 1].first) {
                temp.emplace_back(strs[copy[i + 1].second]);
                i++;
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};
