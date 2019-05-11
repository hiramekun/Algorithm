class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int e: nums) {
            mp[e]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;
        for (auto m: mp) {
            if (que.size() < k) que.push({m.second, m.first});
            else {
                if (que.top().first < m.second) {
                    que.pop();
                    que.push({m.second, m.first});
                }
            }
        }
        vector<int> ans;
        while (!que.empty()) {
            ans.emplace_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};
