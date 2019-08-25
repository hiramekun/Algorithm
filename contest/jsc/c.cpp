/**
 * Created by hiramekun at 20:52 on 2019-08-24.
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
ll factorial(ll n) {
    ll ans = 1;
    while (n > 1) {
        ans *= n;
        ans %= mod;
        n--;
    }
    return ans;
}


int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    n *= 2;

    vector<bool> is_right(n);
    rep(i, n) {
        if (i % 2 == 0 && s[i] == 'W') is_right[i] = true;
        if (i % 2 == 1 && s[i] == 'B') is_right[i] = true;
    }
    ll ans = 1;
    ll left_sum = 0;
    rep(i, n) {
        if (is_right[i]) {
            if (left_sum == 0) {
                cout << 0 << '\n';
                return 0;
            }
            ans *= left_sum;
            ans %= mod;
            left_sum--;
        } else {
            left_sum++;
        }
    }
    if (left_sum > 0) cout << 0 << '\n';
    else cout << ans * factorial(n / 2) % mod << '\n';
    return 0;
}
