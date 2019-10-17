/**
 * Created by hiramekun at 19:23 on 2019-10-17.
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

struct edge {
    ll from, to, cost;

    edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {};
};

class WarshallFloyd {
public:
    int V; // 頂点数
    int E; // 辺の数
    vector<vector<ll> > d; // 最短頂点間距離
    vector<edge> es;

    WarshallFloyd() = default;

    WarshallFloyd(int v) {
        V = v;
        d.resize(v);
        rep(i, v) d[i].resize(v);
        rep(i, v)rep(j, v)d[i][j] = inf;
        rep(i, v) d[i][i] = 0;
    };

    void add(int u, int v, int cost) {
        d[u][v] = cost;
        if (u > v) es.eb(edge(u, v, cost));
    }

    // v: 頂点数, d: 頂点間距離
    void solve() {
        rep(k, V)rep(i, V)rep(j, V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    ll calc() {
        ll ans = 0;
        vector<vector<bool>> notplus(V, vector<bool>(V));
        rep(k, V) rep(i, V) rep(j, V) {
                    if (i == k || k == j) continue;
                    if (d[i][j] == d[i][k] + d[k][j]) {
                        notplus[i][j] = true;
                    }
                }
        rep(i, V) rep(j, V) {
                if (j > i && !notplus[i][j]) ans += d[i][j];
            }
        return ans;
    }
};


void solve() {
    ll n;
    cin >> n;
    WarshallFloyd graph(n);
    vvl a(n, vl(n));
    rep(i, n) {
        rep(j, n) {
            ll tmp;
            cin >> tmp;
            graph.add(i, j, tmp);
            a[i][j] = tmp;
        }
    }
    graph.solve();
    vvl d = graph.d;
    rep(i, n) {
        rep(j, n) {
            if (d[i][j] != a[i][j]) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << graph.calc() << '\n';
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
