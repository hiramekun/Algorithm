#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)

struct edge {
    ll from, to, cost;

    edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {};
};

typedef vector<edge> ve;
typedef vector<ve> vve;

class DAG {
private:
    ll v;
    vve table;
    vl d;
    vl pre; // 最短路の直前の頂点
    ve edges;
public:
    // v: 頂点数
    explicit DAG(ll v) : v(v) {
        table.resize(v);
        pre.resize(v, -1);
        d.resize(v, ll_inf);
    }

    void add(ll from, ll to, ll cost = 1) {
        edge e1(from, to, cost);
        table[from].emplace_back(e1);
        edges.emplace_back(e1);
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
        rep(_, v - 1) {
            for (const auto &e1 : edges) {
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
        rep(_, v - 1) {
            for (const auto &e1 : edges) {
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