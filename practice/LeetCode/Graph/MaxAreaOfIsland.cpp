class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));

        const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int temp = 0;
                if (seen[i][j]) continue;
                seen[i][j] = true;
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    temp++;
                }

                while (!q.empty()) {
                    pair<int, int> now = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = now.first + dx[k], ny = now.second + dy[k];
                        if (0 <= nx && nx <= grid.size() - 1 && 0 <= ny && ny <= grid[i].size() - 1) {
                            if (!seen[nx][ny] && grid[nx][ny] == 1) {
                                temp++;
                                q.push({nx, ny});
                                seen[nx][ny] = true;
                            }
                        }
                    }
                }
                ans = max(temp, ans);
            }
        }
        return ans;
    }
};
