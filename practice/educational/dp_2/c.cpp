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
        ll n;
        cin >> n;
        ll abc[n][3];
        rep(i, n) {
            rep(j, 3)cin >> abc[i][j];
        }

        ll dp[n + 1][3];
        rep(i, n + 1) rep(j, 3) dp[i][j] = 0;
        rep(i, n) {
            rep(j, 3) {
                rep(k, 3) {
                    if (j == k) continue;
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + abc[i][j]);
                }
            }
        }
        ll ans = 0;
        rep(i, 3) ans = max(dp[n][i], ans);
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}