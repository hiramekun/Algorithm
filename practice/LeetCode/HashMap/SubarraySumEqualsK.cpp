class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> d(nums.size() + 1);
        unordered_map<int, int> mp;
        mp[0]++;
        d[0] = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            d[i + 1] = d[i] + nums[i];
            ans += mp[d[i + 1] - k];
            mp[d[i + 1]]++;
        }
        return ans;
    }
};
