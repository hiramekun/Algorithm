/**
 * Created by hiramekun at 21:53 on 2019-09-14.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll n;
    cin >> n;
    string s;
    cin >> s;
    vl a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    vector<bool> isInitialOn(n);
    ll ans = 0;
    rep(i, n) if (s[i] == '1') isInitialOn[i] = true, ans++;

    ll maxT = ll(1e5);
    rep(i, maxT) {
        ll tmp = 0;
        rep(j, n) {
            if (i < b[j]) {
                if (s[j] == '1') tmp++;
                continue;
            }

            ll time = (i - b[j]) / a[j];
            if (time % 2 != 0) {
                if (isInitialOn[j]) tmp++;
            } else {
                if (!isInitialOn[j]) tmp++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}
