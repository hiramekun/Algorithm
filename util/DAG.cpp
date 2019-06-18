#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using v = vector<T>;
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
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

struct edge {
    ll cost;
    ll to;

    edge(ll to, ll cost) : to(to), cost(cost) {};
};

typedef vector<edge> ve;
typedef vector<ve> vve;

class DAG {
private:
    ll v, e;
    vve table;
public:
    // v: 頂点数
    // e: 辺の数
    DAG(ll v, ll e) : v(v), e(e) {
        table.resize(v);
    }

    void add(ll from, ll to, ll cost = 1) {
        table[from].eb(edge(to, cost));
    }

    // O(v + e)
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    vl sort() {
        stack<ll> st; // 入力次数が0の頂点集合
        vl in_d(v); // 頂点の入力次数

        each(e1, table) {
            each(e2, e1) in_d[e2.to]++;
        }
        rep(i, v) if (in_d[i] == 0) st.push(i);
        vl ans; // ソート後のグラフ

        while (!st.empty()) {
            ll i = st.top();
            st.pop();
            ans.eb(i);
            each(ele, table[i]) {
                ll j = ele.to;
                in_d[j]--;
                if (in_d[j] == 0) st.push(j);
            }
        }

        return ans;
    }

    // O(e * logv)
    vl dijkstra(ll s) {
        vl d(v, inf);
        vl pre(v, -1); // 最短路の直前の頂点
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
};

