/**
 * Created by hiramekun at 21:18 on 2019-09-28.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> key;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        ll s = 0;
        rep(j, b) {
            ll c;
            cin >> c;
            c--;
            s |= 1 << c;
        }
        key.emplace_back(s, a);
    }
    ll pow2 = 1 << n;
    vector<ll> dp(pow2, ll_inf); // dp[i]: 集合iの宝箱を開ける最小コスト
    dp[0] = 0;

    rep(s, pow2) {
        rep(i, m) {
            ll t = s | key[i].first; // 遷移先
            ll cost = dp[s] + key[i].second;
            dp[t] = min(dp[t], cost);
        }
    }
    ll ans = dp.back();
    if (ans == ll_inf) ans = -1;
    cout << ans << '\n';
    return 0;
}
