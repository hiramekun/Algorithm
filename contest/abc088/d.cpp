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

const int MAX_H = 50;
int H, W;
char s[MAX_H][MAX_H];
int w_count;
int d_min[MAX_H][MAX_H];

int bfs() {
    queue<P> que;
    REP(i, H) REP(j, W) d_min[i][j] = INF;
    que.push(P(0, 0)), d_min[0][0] = 0;

    // queが空でない限り
    while (!que.empty()) {
        // 一番近いところのを取り出す．
        P p = que.front();
        que.pop();
        if (p.first == H - 1 && p.second == W - 1) break;
        // 近傍4カ所を調べる
        REP(i, 4) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            // 移動可能なマスの場合
            if (0 <= nx && nx < H && 0 <= ny && ny < W && s[nx][ny] != '#' &&
                d_min[nx][ny] == INF) {
                // queに入れて，最小値更新
                que.push(P(nx, ny));
                d_min[nx][ny] = d_min[p.first][p.second] + 1;
            }
        }
    }
    return d_min[H - 1][W - 1];
}

void solve() {
    int res = bfs();
    if (res == INF) cout << -1 << endl;
    else cout << w_count - res - 1 << endl;
}

int main() {
    cin >> H >> W;
    REP(i, H) REP(j, W) {
            cin >> s[i][j];
            if (s[i][j] == '.') w_count++;
        }
    solve();
    return 0;
}
