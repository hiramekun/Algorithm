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

void solve() {
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = unordered_map<ll, ll>();
#pragma clang diagnostic pop
#endif
        ll n, k;
        cin >> n >> k;
        vector<ll> h(n);
        rep(i, n) cin >> h[i];

        ll dp[n + 1000];
        fill(dp, dp + n + 1000, inf);
        dp[0] = 0;
        rep(i, n) {
            repone(j, k) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
            }
        }
        cout << dp[n - 1] << endl;


        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}