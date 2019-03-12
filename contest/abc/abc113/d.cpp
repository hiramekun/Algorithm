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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = unordered_map<ll, ll>();
#pragma clang diagnostic pop
#endif
        ll h, w, k;
        cin >> h >> w >> k;
        ll dp[h + 1][w];
        rep(i, h + 1)rep(j, w) dp[i][j] = 0;
        dp[0][0] = 1;
        rep(i, h) {
            rep(j, w) {
                rep(l, (1LL << (w - 1))) {
                    if (l & (l >> 1)) continue;

                    if (j + 1 <= w - 1 && (l >> j & 1)) {
                        dp[i + 1][j + 1] += dp[i][j];
                        dp[i + 1][j + 1] %= mod;
                    } else if (j - 1 >= 0 && (l >> (j - 1) & 1)) {
                        dp[i + 1][j - 1] += dp[i][j];
                        dp[i + 1][j - 1] %= mod;
                    } else {
                        dp[i + 1][j] += dp[i][j];
                        dp[i + 1][j] %= mod;
                    }
                }
            }
        }
        cout << dp[h][k - 1] << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}