/**
 * Created by hiramekun at 19:22 on 2019-08-26.
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

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
struct edge {
    ll from;
    ll to;
    ll cost;

    edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {};
};

typedef vector<edge> ve;
typedef vector<ve> vve;

class DAG {
private:
    ll v, e;
    vve table;
    vl d;
    vl pre; // 最短路の直前の頂点
    ve edges;
public:
    // v: 頂点数
    // e: 辺の数
    DAG(ll v, ll e) : v(v), e(e) {
        table.resize(v);
        pre.resize(v, -1);
        d.resize(v, ll_inf);
    }

    void add(ll from, ll to, ll cost = 1) {
        edge e1(from, to, cost);
        table[from].eb(e1);
        edges.eb(e1);
    }

    // 負の重みがあっても動く
    // O(v * e)
    vl bellman_ford(ll s) {
        d[s] = 0;
        rep(_, v - 1) {
            rep(i, e) {
                edge e1 = edges[i];
                if (d[e1.from] != ll_inf && d[e1.to] > d[e1.from] + e1.cost) {
                    d[e1.to] = d[e1.from] + e1.cost;
                }
            }
        }
        return d;
    }

    // 各頂点までに到達する経路中に負の閉路が存在するか
    // bellman_fortで最短経路を出した後に使う
    vector<bool> has_negative_loop_in_path() {
        vector<bool> has_loop(v, false);
        rep(_, v - 1) {
            rep(i, e) {
                edge e1 = edges[i];

                if (d[e1.from] != ll_inf && d[e1.to] > d[e1.from] + e1.cost) {
                    has_loop[e1.from] = true;
                }
                if (has_loop[e1.from]) {
                    has_loop[e1.to] = true;
                }
            }
        }
        return move(has_loop);
    }

    // O(e * logv)
    vl dijkstra(ll s) {
        // pairを使っているのは、比較関数を利用するため
        priority_queue<P, vector<P>, greater<>> que;
        d[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            ll min_v = p.S;
            if (d[min_v] < p.F) continue;
            each(ele, table[min_v]) {
                if (d[ele.to] > d[min_v] + ele.cost) {
                    d[ele.to] = d[min_v] + ele.cost;
                    pre[ele.to] = min_v;
                    que.push(P(d[ele.to], ele.to));
                }
            }
        }
        return d;
    }

    // 頂点tへの最短路
    // dijkstraで最短経路を出した後に使う
    vector<int> get_path(int t) {
        vector<int> path;
        for (; t != -1; t = pre[t]) path.emplace_back(t); // tがsになるまでpre[t]をたどっていく
        reverse(path.begin(), path.end());
        return move(path);
    }
};

void solve() {
    ll n, m, s, t;
    cin >> n >> m;

    DAG dag(e5 * 3, m * 3);

    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        dag.add(u, v + e5, 1);
        dag.add(u + e5, v + 2 * e5, 1);
        dag.add(u + 2 * e5, v, 1);
    }

    cin >> s >> t;
    s--, t--;
    vl ans = dag.dijkstra(s);
    if (ans[t] == ll_inf) cout << -1 << '\n';
    else cout << ans[t] / 3 << '\n';
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


