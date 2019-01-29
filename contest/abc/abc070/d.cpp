#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

const int MAX_V = half_inf;

struct edge {
    ll to, cost;
};

ll n, q, k;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<> > que;
    fill(d, d + n, ll_inf);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); // queから最短距離が最小のものを取り出す
        que.pop();
        ll v = p.second; // 最短距離が最小のものの頂点
        if (d[v] < p.first) continue; // すでに最短距離が小さければ
        rep(i, G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                // 頂点vから張っている頂点への最短距離を求め，それを次にqueに入れる．
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin >> n;
    rep(i, n - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge e1 = {b, c};
        G[a].emplace_back(e1);
        edge e2 = {a, c};
        G[b].emplace_back(e2);
    }
    cin >> q >> k;
    k--;
    dijkstra(k);
    rep(i, q) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        cout << d[x] + d[y] << endl;
    }
    return 0;
}
