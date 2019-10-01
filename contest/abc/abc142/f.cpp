/**
 * Created by hiramekun at 15:49 on 2019-09-30.
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

typedef vector<edge> ve;
typedef vector<ve> vve;

class Graph {
private:
    ll v;
    vve table;
    vl pre; // 最短路の直前の頂点
    ve edges;
public:
    vl d;

    // v: 頂点数
    explicit Graph(ll v) : v(v) {
        table.resize(v);
        pre.resize(v, -1);
        d.resize(v, ll_inf);
    }

    void add(ll from, ll to, ll cost = 1) {
        edge e1(from, to, cost);
        table[from].emplace_back(e1);
        edges.emplace_back(e1);
    }

    vl bfs(ll s) {
        queue<ll> que;
        que.push(s);
        pre.assign(v, -1);
        d.assign(v, ll_inf);
        d[s] = 0;
        while (!que.empty()) {
            ll now = que.front();
            que.pop();
            each(e, table[now]) {
                if (d[e.to] != ll_inf) continue;
                d[e.to] = d[e.from] + 1;
                pre[e.to] = e.from;
                que.push(e.to);
            }
        }

        P best(ll_inf, -1);
        rep(i, v) {
            if (i == s) continue;
            each(e, table[i]) {
                if (e.to == s) {
                    best = min(best, {d[e.from], e.from});
                }
            }
        }
        if (best.F == ll_inf) return vl(v + 1);
        vl ret;
        ll now = best.S;
        while (now != -1) {
            ret.eb(now + 1);
            now = pre[now];
        }
        return ret;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    Graph dag(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        dag.add(a, b);
    }
    vl ans(n + 1);
    rep(i, n) {
        vl tmp = dag.bfs(i);
        if (tmp.size() < ans.size()) ans = tmp;
    }
    if (ans.size() == n + 1) {
        cout << -1 << '\n';
        return;
    }
    cout << ans.size() << '\n';
    each(e, ans) cout << e << '\n';
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
