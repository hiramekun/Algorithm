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


class WarshallFloyd {
public:
    int V; // 頂点数
    int E; // 辺の数
    vector<vector<ll> > d; // 最短頂点間距離
    WarshallFloyd() = default;

    WarshallFloyd(int v, int e) {
        V = v, E = e;
        d.resize(v);
        rep(i, v) d[i].resize(v);
        rep(i, v)rep(j, v)d[i][j] = inf;
        rep(i, v) d[i][i] = 0;
    };

    void add(int u, int v, ll cost) {
        d[u][v] = cost;
    }

    // v: 頂点数, d: 頂点間距離
    void solve() {
        rep(k, V)rep(i, V)rep(j, V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
};

// 頂点数V, 辺の数E
const ll MAX_E = 100 * 100;
ll V, E;
int a[MAX_E], b[MAX_E];
ll c[MAX_E];
WarshallFloyd wf;

void solve() {
    ll ans = 0;
    wf.solve();
    rep(i, E) if (wf.d[a[i]][b[i]] != c[i]) ans++;
    cout << ans << endl;
}


int main() {
    cin >> V >> E;
    wf = WarshallFloyd(V, E);
    rep(i, E) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        wf.add(a[i], b[i], c[i]);
        wf.add(b[i], a[i], c[i]);
    }
    solve();
    return 0;
}
