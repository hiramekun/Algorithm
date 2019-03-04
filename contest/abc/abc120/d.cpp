#include <cstring>
#include <sstream>
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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;
struct edge {
    ll u, v;
};
vector<edge> g;
ll n, m;

class UnionFind {
public:
    vector<ll> par; // 親
    vector<ll> rank; // 木の深さ
    vector<ll> _size;

    explicit UnionFind(unsigned int n) {
        par.resize(n);
        rank.resize(n);
        _size.resize(n);
        rep(i, n) {
            par[i] = i;
            rank[i] = 0;
            _size[i] = 1;
        }
    }

    // 木の根を求める
    ll find(ll x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    ll size(ll x) {
        return _size[find(x)];
    }

    // xとyの属する集合を併合
    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        _size[x] = _size[y] = _size[x] + _size[y];
    }

    // xとyが同じ集合に属するか否か
    bool is_same(ll x, ll y) {
        return find(x) == find(y);
    }
};


void solve() {
    ll ans[m];
    rep(i, m) ans[i] = n * (n - 1) / 2;
    UnionFind tree = UnionFind(n);
    for (int i = m - 2; i >= 0; --i) {
        ll a = g[i + 1].u, b = g[i + 1].v;
        if (tree.is_same(a, b)) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = ans[i + 1] - tree.size(a) * tree.size(b);
            tree.unite(a, b);
        }
    }
    rep(i, m) cout << ans[i] << endl;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> n >> m;
        g.resize(m);
        rep(i, m) {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            edge e = {a, b};
            g[i] = e;
        }

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}