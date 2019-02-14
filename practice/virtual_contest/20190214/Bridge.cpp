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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

const int max_n = 50;
int n, m, a[max_n], b[max_n];
bool g[max_n][max_n];
bool seen[max_n];

void dfs(int now) {
    seen[now] = true;
    rep(i, n) {
        if (!g[now][i]) continue;
        if (seen[i]) continue;
        dfs(i);
    }
}

void solve() {
    int ans = 0;
    rep(i, m) {
        g[a[i]][b[i]] = g[b[i]][a[i]] = false;
        fill(seen, seen + n, false);
        dfs(0);

        rep(j, n) {
            if (!seen[j]) {
                ans++;
                break;
            }
        }

        g[a[i]][b[i]] = g[b[i]][a[i]] = true;
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    fill(g[0], g[n], false);
    rep(i, m) {
        int ta, tb;
        cin >> ta >> tb;
        ta--, tb--;
        a[i] = ta, b[i] = tb;
        g[ta][tb] = g[tb][ta] = true;
    }
    solve();
    return 0;
}
