#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_R = 50;
int R, C;
P s, g;
char c[MAX_R][MAX_R];
int d_min[MAX_R][MAX_R];

int bfs() {
    queue<P> que;
    REP(i, R) REP(j, C) d_min[i][j] = INF;
    que.push(s), d_min[s.first][s.second] = 0;

    // queが空でない限り
    while (!que.empty()) {
        // 一番近いところのを取り出す．
        P p = que.front();
        que.pop();
        if (p.first == g.first && p.second == g.second) break;
        // 近傍4カ所を調べる
        REP(i, 4) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            // 移動可能なマスの場合
            if (0 <= nx && nx < R && 0 <= ny && ny < C && c[nx][ny] != '#' &&
                d_min[nx][ny] == INF) {
                // queに入れて，最小値更新
                que.push(P(nx, ny));
                d_min[nx][ny] = d_min[p.first][p.second] + 1;
            }
        }
    }
    return d_min[g.first][g.second];
}

void solve() {
    int res = bfs();
    cout << res << endl;
}

int main() {
    cin >> R >> C;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    s = P(sx - 1, sy - 1), g = P(gx - 1, gy - 1);
    REP(i, R) REP(j, C) cin >> c[i][j];
    solve();
    return 0;
}
