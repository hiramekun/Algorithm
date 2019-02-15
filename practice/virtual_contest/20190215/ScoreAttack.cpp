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
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

const int MAX_V = 1000, MAX_E = 2000;

struct edge {
    ll from, to, cost;
};


edge es[MAX_E];
ll d[MAX_V];
bool has_loop[MAX_V];
ll V, E; // Vは頂点数，Eは辺数

// s番目の頂点から各頂点への最短距離を求める
// V * E
void bellman_ford(ll s) {
    for (int i = 0; i < V; ++i) d[i] = -ll_inf;
    d[s] = 0;
    for (int j = 0; j < V - 1; j++) {
        for (int i = 0; i < E; ++i) {
            edge e = es[i];
            if (d[e.to] < d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
}


void solve() {
    bellman_ford(0);
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            edge e = es[i];

            if (d[e.to] < d[e.from] + e.cost) {
                has_loop[e.from] = true;
            }
            if (has_loop[e.from]) {
                has_loop[e.to] = true;
            }
        }
    }
    if (has_loop[V - 1]) cout << "inf" << endl;
    else cout << d[V - 1] << endl;
}

int main() {
    cin >> V >> E;
    rep(i, E) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge e = {a, b, c};
        es[i] = e;
    }
    solve();
    return 0;
}
