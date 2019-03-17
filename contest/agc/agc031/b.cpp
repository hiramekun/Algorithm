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
        vector<ll> c(n);
        rep(i, n) cin >> c[i];

        ll dp[n]; // dp[i] iで区切った時の場合の数
        dp[0] = 1;
        mp[c[0]] = 1;

        for (int i = 1; i < n; ++i) {
            if (c[i] != c[i - 1]) {
                dp[i] = dp[i - 1] + mp[c[i]];
            } else {
                dp[i] = dp[i - 1];
            }
            dp[i] %= mod;
            mp[c[i]] = dp[i];
        }
        cout << dp[n - 1] << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}