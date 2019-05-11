class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto c = [](pair<int, int> &p1, pair<int, int> &p2) {return p1.first + p1.second < p2.first + p2.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(c)> que(c);
        for (int n1: nums1) {
            for (int n2: nums2) {
                if (que.size() < k) que.push({n1, n2});
                else {
                    if (n1 + n2 < que.top().first + que.top().second) {
                        que.pop();
                        que.push({n1, n2});
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while (!que.empty()) {
            int e1 = que.top().first;
            int e2 = que.top().second;
            que.pop();
            vector<int> tmp{e1, e2};
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
