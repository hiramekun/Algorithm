/**
 * Created by hiramekun at 15:21 on 2019-09-03.
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
    ll v, e;
    vve table;
    vl d;
    vl pre; // 最短路の直前の頂点
    ve edges;
public:
    // v: 頂点数
    // e: 辺の数
    Graph(ll v) : v(v) {
        table.resize(v);
        pre.resize(v, -1);
        d.resize(v, ll_inf);
    }

    void add(ll from, ll to, ll cost = 1) {
        edge e1(from, to, cost);
        table[from].emplace_back(e1);
        edges.emplace_back(e1);
        e++;
    }

    // O(v + e)
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    vl sort() {
        stack<ll> st; // 入力次数が0の頂点集合
        vl in_d(v);
        for (const auto ele: edges) {
            in_d[ele.to]++;
        }

        rep(i, v) if (in_d[i] == 0) {
                st.push(i);
            }
        vl ans; // ソート後のグラフ

        while (!st.empty()) {
            ll i = st.top();
            st.pop();
            ans.emplace_back(i);
            for (const auto j: table[i]) {
                ll to = j.to;
                in_d[to]--;
                if (in_d[to] == 0) st.push(to);
            }
        }

        return move(ans);
    }

    // O(v + e)
    // 閉路が存在するときは-1を返す
    ll get_longest_path() {
        vector<bool> seen(v), calc(v);
        vl d(v, 0);
        auto dfs = [&](auto &&f, ll now) -> ll {
            if (seen[now]) {
                if (!calc[now]) return -1;
                return d[now];
            }
            seen[now] = true;
            d[now] = 1;
            for (const auto &t: table[now]) {
                ll res = f(f, t.to);
                if (res == -1) return -1;
                d[now] = max(res + t.cost, d[now]);
            }
            calc[now] = true;
            return d[now];
        };

        ll ans = 0;
        rep(i, v) {
            ll tmp = dfs(dfs, i);
            if (tmp == -1) {
                return -1;
            }
            ans = max(tmp, ans);
        }
        return ans;
    }

    // 負の重みがあっても動く
    // O(v * e)
    vl bellman_ford(ll s) {
        d[s] = 0;
        for (int j = 0; j < v - 1; j++) {
            for (int i = 0; i < e; ++i) {
                edge e1 = edges[i];
                if (d[e1.from] != ll_inf && d[e1.to] > d[e1.from] + e1.cost) {
                    d[e1.to] = d[e1.from] + e1.cost;
                }
            }
        }
        return move(d);
    }

    // 各頂点までに到達する経路中に負の閉路が存在するか
    // bellman_fortで最短経路を出した後に使う
    vl has_negative_loop_in_path() {
        vl has_loop(v, false);
        for (ll i = 0; i < v - 1; ++i) {
            for (ll j = 0; j < e; ++j) {
                edge e1 = edges[i];

                if (d[e1.to] > d[e1.from] + e1.cost) {
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
            ll min_v = p.second;
            if (d[min_v] < p.first) continue;
            for (const auto &ele: table[min_v]) {
                if (d[ele.to] > d[min_v] + ele.cost) {
                    d[ele.to] = d[min_v] + ele.cost;
                    pre[ele.to] = min_v;
                    que.push(P(d[ele.to], ele.to));
                }
            }
        }
        return move(d);
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
    ll n;
    cin >> n;
    vvl ptov(n, vl(n));
    vvl a(n, vl(n - 1));
    rep(i, n) {
        rep(j, n - 1) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    ll tmp = 0;
    rep(i, n - 1) {
        for (ll j = i + 1; j < n; ++j) {
            ptov[i][j] = tmp++;
        }
    }
    auto to_id = [&](ll i, ll j) -> ll {
        auto ij = minmax(i, j);
        return ptov[ij.F][ij.S];
    };
    Graph dag(tmp);
    rep(i, n) {
        rep(j, n - 1) {
            a[i][j] = to_id(i, a[i][j]);
        }
    }
    rep(i, n) {
        rep(j, n - 2) {
            dag.add(a[i][j], a[i][j + 1]);
        }
    }
    ll ans = dag.get_longest_path();
    cout << ans << '\n';
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
