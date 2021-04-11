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

    void add(int u, int v, int cost) {
        d[u][v] = cost;
    }

    // v: 頂点数, d: 頂点間距離
    void solve() {
        rep(k, V)rep(i, V)rep(j, V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
};

int n, m;
WarshallFloyd wf;

void solve() {
    wf.solve();
    vector<vector<ll> > d = wf.d;
    rep(i, n)rep(j, n) cout << d[i][j] << endl;
}

int main() {
    cin >> n >> m;
    wf = WarshallFloyd(n, m);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        // 0-index
        a--, b--;
        wf.add(a, b, c);
        // 無向グラフの場合
        wf.add(b, a, c);
    }
    solve();
    return 0;
}
