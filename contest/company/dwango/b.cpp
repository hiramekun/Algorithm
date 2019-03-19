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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];
        ll dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + a[i - 1];
        }
        vector<ll> v;
        rep(i, n + 1) {
            for (ll j = i + 1; j <= n; ++j) {
                v.emplace_back(dp[j] - dp[i]);
            }
        }

        vector<bool> use(v.size());
        rep(i, use.size()) use[i] = true;
        repr(i, 40) {
            ll temp = 0;
            for (int j = 0; j < v.size(); ++j) {
                if (use[j] && (v[j] >> i & 1)) temp++;
            }

            if (temp >= k) {
                for (int j = 0; j < v.size(); ++j) {
                    if (!(v[j] >> i & 1)) use[j] = false;
                }
            }
        }
        ll ans = 0;
        rep(i, v.size()) if (use[i]) ans = (ans == 0 ? v[i] : ans & v[i]);
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}
