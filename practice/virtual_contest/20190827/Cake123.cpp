/**
 * Created by hiramekun at 20:07 on 2019-08-27.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define all(obj) (obj).begin(), (obj).end()

int main() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vl a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];

    vl ab;
    rep(i, x) rep(j, y) ab.emplace_back(a[i] + b[j]);
    sort(all(ab), greater<>());
    sort(all(c), greater<>());

    vl ans;
    rep(i, min(k, x * y)) rep(j, min(k, z)) ans.emplace_back(ab[i] + c[j]);
    sort(all(ans), greater<>());

    rep(i, k) cout << ans[i] << '\n';

    return 0;
}
