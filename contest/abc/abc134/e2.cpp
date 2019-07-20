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

    deque<ll> dq;
    rep(i, n) {
        ll idx = lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();
        if (idx == 0) dq.push_front(a[i]);
        else dq[idx - 1] = a[i];
    }
    cout << dq.size() << endl;
    return 0;
}
