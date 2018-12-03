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
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int MAX_H = 500;
int H, W;
pair<int, int> idx_s, idx_g;
char c[MAX_H][MAX_H];
bool seen[MAX_H][MAX_H];

bool dfs(int h, int w) {
    seen[h][w] = true;
    if (h == idx_g.first && w == idx_g.second) return true;
    if (h + 1 < H && !seen[h + 1][w] && c[h + 1][w] != '#') if (dfs(h + 1, w)) return true;
    if (w + 1 < W && !seen[h][w + 1] && c[h][w + 1] != '#') if (dfs(h, w + 1)) return true;
    if (h - 1 >= 0 && !seen[h - 1][w] && c[h - 1][w] != '#') if (dfs(h - 1, w)) return true;
    if (w - 1 >= 0 && !seen[h][w - 1] && c[h][w - 1] != '#') if (dfs(h, w - 1)) return true;
    return false;
}

void solve() {
    if (dfs(idx_s.first, idx_s.second)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    cin >> H >> W;
    REP(i, H) REP(j, W) {
            cin >> c[i][j];
            if (c[i][j] == 's') idx_s = make_pair(i, j);
            if (c[i][j] == 'g') idx_g = make_pair(i, j);
        }
    solve();
    return 0;
}
