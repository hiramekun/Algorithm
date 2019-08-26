/**
 * Created by hiramekun at 14:58 on 2019-08-26.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define all(obj) (obj).begin(), (obj).end()

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}

int main() {

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> divs = divisor(accumulate(all(a), 0LL));

    ll ans = 0;
    each(e, divs) {
        vector<ll> mods(n);
        rep(i, n) mods[i] = a[i] % e;
        sort(all(mods));

        vector<ll> minus(n + 1);
        rep(i, n) minus[i + 1] = minus[i] + mods[i];

        vector<ll> plus(n + 1);
        repr(i, n) plus[i] = plus[i + 1] + e - mods[i];

        for (ll i = 0; i <= n; ++i) {
            if (max(plus[i], minus[i]) <= k) ans = max(ans, e);
        }
    }
    cout << ans << '\n';
    return 0;
}
