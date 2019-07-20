#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

int main() {

    ll n;
    cin >> n;
    vector<ll> a(n);

    rep(i, n) cin >> a[i];
    vector<ll> d;

    rep(i, n) {
        auto itr = lower_bound(d.rbegin(), d.rend(), a[i]);
        if (itr == d.rbegin()) {
            d.emplace_back(a[i]);
        } else {
            itr--;
            *itr = a[i];
        }
    }
    cout << d.size() << endl;
    return 0;
}
