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

ll n;
vector<ll> a, dp;
unordered_map<ll, ll> mp;

void solve() {
    ll ans = 0;
    each(i, mp) {
        if (i.first == 0) {
            ll temp = 1;
            while (i.second > 1) {
                temp += i.second;
                i.second--;
            }
            ans += temp;
        } else {
            ans += (i.second * (i.second - 1) / 2);
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    a.resize(n);
    dp.resize(n + 1);
    dp[0] = 0;
    rep(i, n) {
        cin >> a[i];
        dp[i + 1] = dp[i] + a[i];
        mp[dp[i + 1]]++;
    }
    solve();
    return 0;
}
