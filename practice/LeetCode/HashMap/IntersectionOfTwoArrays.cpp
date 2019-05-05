class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int v: nums1) if (mp[v] == 0) mp[v]++;
        for (int v: nums2) if (mp[v] == 1) mp[v]++;
        vector<int> ans;
        for (auto m: mp) if (m.second == 2) ans.emplace_back(m.first);
        return ans;
    }
};
