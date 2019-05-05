class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            for (int i = 0; i < strs.size(); i++) {
                string copy(strs[i]);
                sort(copy.begin(), copy.end());
                mp[copy].emplace_back(strs[i]);
            }
            vector<vector<string>> ans;
            for (auto m: mp) {
                ans.emplace_back(m.second);
            }  
            delete mp;
            return ans;
        }
};
