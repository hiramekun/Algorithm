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

struct edge {
    int to, cost;

    edge(int to, int cost) : to(to), cost(cost) {}
};

vector<edge> G[half_inf];
vector<ll> L, R, D, ans;
vector<bool> searched;

bool dfs(int v) {
    searched[v] = true;
    rep(i, G[v].size()) {
        if (ans[G[v][i].to] == inf) {
            ans[G[v][i].to] = ans[v] + G[v][i].cost;
        }
        if (ans[G[v][i].to] != ans[v] + G[v][i].cost) {
            cout << "No" << endl;
            exit(0);
        }
        if (!searched[G[v][i].to]) dfs(G[v][i].to);
    }
}

void solve() {
    rep(i, n) {
        if (!searched[i]) {
            ans[i] = 0;
            dfs(i);
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin >> n >> m;
    L.resize(m), R.resize(m), D.resize(m);
    searched.resize(n);
    ans.resize(n);
    fill(ans.begin(), ans.end(), inf);
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        L[i] = l, R[i] = r, D[i] = d;
        edge e1(r, d), e2(l, -d);
        G[l].emplace_back(e1);
        G[r].emplace_back(e2);
    }
    solve();
    return 0;
}
