/**
 * Created by hiramekun at 00:36 on 2019-08-31.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for(auto& i:mp)

int main() {

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    unordered_map<ll, vector<ll>> mp;
    rep(i, n) {
        ll t = 0;
        while (a[i] > 0) {
            mp[a[i]].emplace_back(t);
            a[i] /= 2;
            t++;
        }
    }

    ll ans = 1e18;
    each(e, mp) {
        vector<ll> times = e.second;
        if (times.size() >= k) {
            sort(times.begin(), times.end());
            ll now = accumulate(times.begin(), times.begin() + k, 0LL);
            ans = min(ans, now);
        }
    }
    cout << ans << '\n';
    return 0;
}


