#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


const int MAX_N = 50;
const int MAX_M = (MAX_N + 1) * (MAX_N);
int N, M, a[MAX_M], b[MAX_M];
bool used[MAX_N + 1];       // used[i]: iがすでに使われたかどうか.
bool G[MAX_N + 1][MAX_N + 1];

void solve() {
    int ans = 0;
    queue<int> que;
    rep(i, M) {
        fill(used, used + (N + 1), false);
        bool g[N + 1][N + 1];
        fill(g[0], g[N + 1], false);
        rep(n, M) g[a[n]][b[n]] = G[a[n]][b[n]], g[b[n]][a[n]] = G[b[n]][a[n]];

        g[a[i]][b[i]] = false, g[b[i]][a[i]] = false;
        que.push(1);
        int count = 0;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (!used[v]) count++;
            used[v] = true;
            repone(j, N) {
                if (g[v][j]) {
                    que.push(j);
                    g[v][j] = false, g[j][v] = false;
                }
            }
        }
        if (count != N) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        cin >> a[i] >> b[i];
        G[a[i]][b[i]] = true;
        G[b[i]][a[i]] = true;
    }
    solve();
    return 0;
}
