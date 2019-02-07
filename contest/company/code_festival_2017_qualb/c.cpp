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
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll n, m;
vector<ll> G[half_inf + 10];
int c = 1;
int color[half_inf + 10];

bool dfs(ll v, int c) {
    color[v] = c;
    rep(i, G[v].size()) {
        if (color[G[v][i]] == 0) {
            if (!dfs(G[v][i], -c)) return false;
        } else if (color[G[v][i]] == c) return false;
    }
    return true;
}

void solve() {
    if (dfs(0, c)) {
        ll n_1 = 0, n_2 = 0;
        rep(i, n) {
            if (color[i] == c) n_1++;
            if (color[i] == -c) n_2++;
        }
        cout << n_1 * n_2 - m << endl;
    } else {
        cout << n * (n - 1) / 2 - m << endl;
    }
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    solve();
    return 0;
}
