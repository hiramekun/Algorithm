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

        ll dp[n + 1][4][4][4]; // dp[i][j]: i文字使って，最後の文字がjであるような場合の数
        const ll A = 0, C = 1, G = 2, T = 3;
        rep(i, n + 1) rep(j, 4) rep(k, 4) rep(l, 4) dp[i][j][k][l] = 0;
        //mlkj
        for (int i = 2; i < n; ++i) {
            rep(j, 4) { // 現在の数字
                rep(k, 4) { // 1個前の数字
                    rep(l, 4) { // 2個前の数字
                        rep(m, 4) { // 3個前の数字
                            if (l == A && k == G && j == C) continue;
                            if (l == A && k == C && j == G) continue;
                            if (l == G && k == A && j == C) continue;
                            if (m == A && k == G && j == C) continue;
                            if (m == A && l == G && j == C) continue;
                            if (i <= 2) {
                                dp[i + 1][j][k][l] = 1;
                            } else {
                                dp[i + 1][j][k][l] += dp[i][k][l][m];
                            }
                            dp[i + 1][j][k][l] %= mod;
                        }
                    }
                }
            }
        }
        ll ans = 0;
        rep(i, 4) rep(j, 4) rep(k, 4) {
                    ans += dp[n][i][j][k];
                    ans %= mod;
                }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}