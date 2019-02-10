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
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

// 頂点数V, 辺の数E
const ll MAX_E = 100 * 100;
ll V, E;
ll d[100][100];
ll a[MAX_E], b[MAX_E], c[MAX_E];

// v: 頂点数, d: 頂点間距離
void warshall_floyd() {
    rep(k, V)rep(i, V)rep(j, V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {

    warshall_floyd();
    ll ans = 0;
    rep(i, E) if (d[a[i]][b[i]] != c[i]) ans++;
    cout << ans << endl;
}


int main() {
    fill(d[0], d[100], inf);
    cin >> V >> E;
    rep(i, E) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        d[a[i]][b[i]] = c[i];
        d[b[i]][a[i]] = c[i];
    }
    rep(i, V) d[i][i] = 0;
    solve();
    return 0;
}
