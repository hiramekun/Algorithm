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
#include <numeric>
#include <stack>

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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n, W;
        cin >> n >> W;
        ll w[n], v[n];
        rep(i, n) cin >> w[i] >> v[i];

        ll dp[n + 1][half_inf + 100];
        rep(i, n + 1) rep(j, half_inf + 100) dp[i][j] = ll_inf;
        dp[0][0] = 0;

        rep(i, n) {
            rep(j, half_inf + 100) {
                dp[i + 1][j] = dp[i][j];
                if (j >= v[i] && dp[i][j - v[i]] != ll_inf) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
                }
            }
        }

        ll ans = 0;
        rep(i, half_inf + 100) {
            if (dp[n][i] <= W) ans = max(i, ans);
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}