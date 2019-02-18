#include <cstring>
#include <sstream>
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

unordered_map<ll, ll> mp;
ll n, ma, mb;
vector<ll> a, b, c;

void solve() {
    ll dp[n + 1][500][500]; // dp[i][j][k] = i番目まででaをj個，bをk個選んだ時の最小コスト．
    rep(i, n + 1) rep(j, 500) rep(k, 500) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(j, 500) {
            rep(k, 500) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                if (j >= a[i] && k >= b[i]) {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
                }
            }
        }
    }

    ll ans = inf;
    repone(i, 400) {
        repone(j, 400) {
            if (i * mb == ma * j) {
                ans = min(dp[n][i][j], ans);
            }
        }
    }
    cout << (ans == inf ? -1 : ans) << endl;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = unordered_map<ll, ll>();
#pragma clang diagnostic pop
#endif

        cin >> n >> ma >> mb;
        a.resize(n), b.resize(n), c.resize(n);
        rep(i, n) cin >> a[i] >> b[i] >> c[i];
        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}