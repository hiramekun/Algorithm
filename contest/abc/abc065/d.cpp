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
struct edge {
    ll u, v, cost;
};

class UnionFind {
public:
    vector<ll> par; // 親
    vector<ll> rank; // 木の深さ

    explicit UnionFind(unsigned int n) {
        par.resize(n);
        rank.resize(n);
        rep(i, n) {
            par[i] = i;
            rank[i] = 0;
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
    }

    // xとyが同じ集合に属するか否か
    bool is_same(ll x, ll y) {
        return find(x) == find(y);
    }
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

// 頂点数V, 辺の数E
vector<edge> es;
ll n;

// 最小全域木のコストの和を返す．
ll kruskal() {
    sort(es.begin(), es.end(), comp);
    UnionFind u = UnionFind(n);
    ll res = 0;
    each(e, es) {
        if (!u.is_same(e.u, e.v)) {
            u.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

struct info {
    ll idx, x, y;
};
vector<info> v;

bool comp_x(info info1, info info2) {
    return info1.x < info2.x;
}

bool comp_y(info info1, info info2) {
    return info1.y < info2.y;
}


void solve() {
    sort(v.begin(), v.end(), comp_x);
    rep(i, n - 1) {
        edge e = {v[i + 1].idx, v[i].idx, v[i + 1].x - v[i].x};
        es.emplace_back(e);
    }
    sort(v.begin(), v.end(), comp_y);
    rep(i, n - 1) {
        edge e = {v[i + 1].idx, v[i].idx, v[i + 1].y - v[i].y};
        es.emplace_back(e);
    }
    cout << kruskal() << endl;
}

int main() {
    cin >> n;
    ll x, y;
    rep(i, n) {
        cin >> x >> y;
        info info1 = {i, x, y};
        v.emplace_back(info1);
    }
    solve();
    return 0;
}
