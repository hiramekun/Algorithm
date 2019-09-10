/**
 * Created by hiramekun at 20:55 on 2019-09-07.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll ans = 0;
    rep(i, n - 1) {
        if (s[i] == s[i + 1]) ans++;
    }
    ans += 2 * k;
    cout << min(n - 1, ans) << '\n';
    return 0;
}
