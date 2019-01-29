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

ll h, w;
ll c[10][10];
ll a[200][200];

void warshall_floyd() {
    rep(k, 10)rep(i, 10)rep(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
}

void solve() {
    warshall_floyd();

    ll ans = 0;
    rep(i, h)rep(j, w) if (a[i][j] != -1) {
                ans += c[a[i][j]][1];
            }
    cout << ans << endl;
}

int main() {
    cin >> h >> w;
    rep(i, 10)rep(j, 10) cin >> c[i][j];
    rep(i, h)rep(j, w) cin >> a[i][j];
    solve();
    return 0;
}
