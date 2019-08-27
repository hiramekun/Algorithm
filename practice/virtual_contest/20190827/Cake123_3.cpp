/**
 * Created by hiramekun at 22:39 on 2019-08-27.
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

    sort(all(a), greater<>()), sort(all(b), greater<>()), sort(all(c), greater<>());

    auto solve = [&](ll p) -> bool {
        ll cnt = 0;
        rep(i, x) { // ここは最大でK回ループがまわる
            rep(j, y) { // ここから下は最大でK回ループがまわる
                rep(l, z) {
                    ll val = a[i] + b[j] + c[l];
                    if (val < p) break;
                    if (++cnt >= k) {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    ll s = -1, e = a[0] + b[0] + c[0] + 1;
    while (e - s > 1) {
        ll mid = (s + e) / 2;
        if (solve(mid)) s = mid;
        else e = mid;
    }
    vl ans;
    rep(i, x) {
        rep(j, y) {
            rep(l, z) {
                ll val = a[i] + b[j] + c[l];
                if (val < s + 1) break;
                ans.emplace_back(val);
            }
        }
    }
    while (ans.size() < k) ans.emplace_back(s);
    sort(all(ans), greater<>());
    for (auto val: ans) cout << val << '\n';
    return 0;
}


