#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
void dump_debug(T list) {
#ifdef MY_DEBUG
    each(e, list) cout << e << " ";
    printf("\n");
#endif
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
    Graph(ll v, ll e) : v(v), e(e) {
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

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        ll n, m, p;
        cin >> n >> m >> p;
        Graph dag(n, m);
        rep(i, m) {
            ll a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            dag.add(a, b, -(c - p));
        }
        vl d = dag.bellman_ford(0);
        vector<bool> loop = dag.has_negative_loop_in_path();
        if (loop[n - 1]) cout << -1 << endl;
        else cout << max(0LL, -d[n - 1]) << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}