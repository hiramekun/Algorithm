/**
 * Created by hiramekun at 19:13 on 2019-10-22.
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
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

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
class WarshallFloyd {
public:
    int V; // 頂点数
    vector<vector<ll> > d; // 最短頂点間距離
    WarshallFloyd() = default;

    WarshallFloyd(int v) {
        V = v;
        d.resize(v);
        rep(i, v) d[i].resize(v);
        rep(i, v)rep(j, v)d[i][j] = ll_inf;
        rep(i, v) d[i][i] = 0;
    };

    void add(int u, int v, int cost) {
        d[u][v] = cost;
    }

    // v: 頂点数, d: 頂点間距離
    void solve() {
        rep(k, V)rep(i, V)rep(j, V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    vvl solve2(ll l) {
        vvl d2(V, vl(V, ll_inf));
        rep(i, V)rep(j, V) if (d[i][j] <= l) d2[i][j] = 1;
        rep(k, V)rep(i, V)rep(j, V) d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
        return d2;
    }
};

void solve() {
    ll n, m, l;
    cin >> n >> m >> l;
    WarshallFloyd warshallFloyd(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        warshallFloyd.add(a, b, c);
        warshallFloyd.add(b, a, c);
    }
    warshallFloyd.solve();
    vvl ans = warshallFloyd.solve2(l);
    ll q;
    cin >> q;
    rep(i, q) {
        ll s, t;
        cin >> s >> t;
        s--, t--;
        if (ans[s][t] == ll_inf) cout << -1 << '\n';
        else cout << ans[s][t] - 1 << '\n';
    }
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