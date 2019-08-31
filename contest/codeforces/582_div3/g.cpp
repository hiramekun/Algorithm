/**
 * Created by hiramekun at 01:11 on 2019-08-31.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

class UnionFind {
private:
    vector<ll> size; // グループに属する物の数．
public:
    vector<ll> par; // 親
    vector<ll> rank; // 木の深さ

    explicit UnionFind(unsigned int n) {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        rep(i, n) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
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

    // グループのサイズを求める．
    ll calc_size(ll x) {
        return size[find(x)];
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
            if (rank[x] == rank[y])rank[x]++;
        }
        size[x] = size[y] = size[x] + size[y];
    }

    // xとyが同じ集合に属するか否か
    bool is_same(ll x, ll y) {
        return find(x) == find(y);
    }
};

template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
using P = pair<ll, ll>;
using edge = pair<ll, P>;

int main() {

    ll n, m;
    cin >> n >> m;
    minpq<edge> que;
    rep(i, n - 1) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        que.push(edge(c, P(u, v)));
    }
    vector<P> q(m);
    rep(i, m) {
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(q.begin(), q.end());

    vector<ll> ans(m);
    UnionFind uf(n);
    ll cnt = 0;
    rep(i, m) {
        ll target = q[i].first, idx = q[i].second;

        while (!que.empty() && que.top().first <= target) {
            edge now = que.top();
            ll u = now.second.first, v = now.second.second;
            ll s1 = uf.calc_size(u), s2 = uf.calc_size(v);
            cnt -= s1 * (s1 - 1) / 2;
            cnt -= s2 * (s2 - 1) / 2;
            uf.unite(u, v);
            ll s3 = uf.calc_size(u);
            cnt += s3 * (s3 - 1) / 2;
            que.pop();
        }
        ans[idx] = cnt;
    }
    rep(i, m) cout << ans[i] << ' ';
    return 0;
}


