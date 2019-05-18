class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        bool seen[grid.size()][grid[0].size()];
        fill(seen[0], seen[grid.size()], false);

        queue<pair<int, int>> st;
        const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (seen[i][j]) continue;
                if (grid[i][j] == '1') {
                    ans++;
                    st.push({i, j});

                    while (!st.empty()) {
                        pair<int, int> now = st.front();
                        st.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = now.first + dx[k], ny = now.second + dy[k];
                            if (0 <= nx && nx <= grid.size() - 1 && 0 <= ny && ny <= grid[i].size() - 1) {
                                if (!seen[nx][ny] && grid[nx][ny] == '1') {
                                    seen[nx][ny] = true;
                                    st.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
