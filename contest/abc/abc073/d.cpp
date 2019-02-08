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

ll N, M, R, d[200][200];
vector<ll> r;

// v: 頂点数, d: 頂点間距離
void warshall_floyd(ll v) {
    rep(k, v)rep(i, v)rep(j, v) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
    warshall_floyd(N);
    sort(r.begin(), r.end());
    ll ans = ll_inf;
    do {
        ll temp = 0;
        rep(i, R - 1) temp += d[r[i]][r[i + 1]];
        ans = min(temp, ans);
    } while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}

int main() {
    cin >> N >> M >> R;
    r.resize(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }
    rep(i, 200) rep(j, 200) d[i][j] = ll_inf;
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    solve();
    return 0;
}
