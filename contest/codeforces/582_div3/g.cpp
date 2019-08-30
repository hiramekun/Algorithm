/**
 * Created by hiramekun at 01:11 on 2019-08-31.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}


template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

struct edge {
    ll from;
    ll to;
    ll cost;

    edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {};
};

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
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


void solve() {
    ll n, m;
    cin >> n >> m;
    minpq<pair<ll, pair<ll, ll>>> que;
    rep(i, n - 1) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        que.push(make_pair(c, P(u, v)));
    }
    vector<P> q(m);
    rep(i, m) {
        cin >> q[i].F;
        q[i].S = i;
    }
    sort(all(q));

    vl ans(m);
    UnionFind uf(n);
    ll cnt = 0;
    rep(i, m) {
        ll target = q[i].F, idx = q[i].S;

        while (!que.empty() && que.top().F <= target) {
            pair<ll, P> now = que.top();
            ll u = now.S.F, v = now.S.S;
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
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}


