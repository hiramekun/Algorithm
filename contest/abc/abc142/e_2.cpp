/**
 * Created by hiramekun at 13:06 on 2019-09-29.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using P = pair<ll, ll>;
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

struct edge {
    ll from, to, cost;

    edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {};
};

class Graph {
private:
    ll v;
    vector<vector<edge>> table;
    vl d;
public:
    // v: 頂点数
    explicit Graph(ll v) : v(v) {
        table.resize(v);
        d.resize(v, ll_inf);
    }

    void add(ll from, ll to, ll cost = 1) {
        edge e1(from, to, cost);
        table[from].emplace_back(e1);
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
                    que.push(P(d[ele.to], ele.to));
                }
            }
        }
        return move(d);
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    Graph dag(1 << n);

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        ll s = 0;
        rep(j, b) {
            ll c;
            cin >> c;
            c--;
            s |= 1 << c;
        }

        rep(j, 1 << n) {
            dag.add(j, j | s, a);
        }
    }
    vl ans = dag.dijkstra(0);
    if (ans.back() == ll_inf) cout << -1 << '\n';
    else cout << ans.back() << '\n';

    return 0;
}