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
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;

void solve() {
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n, ma, mb;
        cin >> n >> ma >> mb;
        vector<ll> a(n), b(n), c(n);
        rep(i, n) cin >> a[i] >> b[i]jj >> c[i];
        ll suma = accumulate(a.begin(), a.end(), 0);
        ll sumb = accumulate(b.begin(), b.end(), 0);
        ll dp[n + 1][suma + 100][sumb + 100];
        rep(k, n + 1) rep(i, suma + 100)rep(j, sumb + 100) dp[k][i][j] = ll_inf;
        dp[0][0][0] = 0;
        rep(k, n) {
            rep(i, suma + 1) {
                rep(j, sumb + 1) {
                    dp[k + 1][i][j] = min(dp[k + 1][i][j], dp[k][i][j]);
                    if (i >= a[k] && j >= b[k]) {
                        if (dp[k][i - a[k]][j - b[k]] != ll_inf) {
                            dp[k + 1][i][j] = min(dp[k + 1][i][j],
                                                  dp[k][i - a[k]][j - b[k]] + c[k]);
                        }
                    }
                }
            }
        }
        ll ans = ll_inf;
        repone(i, suma) {
            repone(j, sumb) {
                if (i * mb == j * ma) ans = min(ans, dp[n][i][j]);
            }
        }
        if (ans == ll_inf)cout << -1 << endl;
        else cout << ans << endl;

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}