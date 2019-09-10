/**
 * Created by hiramekun at 20:55 on 2019-09-07.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll n;
    cin >> n;
    vl p(n);
    unordered_map<ll, ll> mp;
    set<ll> s;
    rep(i, n) {
        cin >> p[i];
        mp[p[i]] = i;
        s.insert(p[i]);
    }

    set<ll> idx;
    ll ans = 0;
    while (!s.empty()) {
        ll now = *s.rbegin();
        s.erase(now);

        ll i = mp[now];
        vl l(2, -1), r(2, n);
        {
            auto itr = idx.lower_bound(i);
            rep(j, 2) { // r
                if (itr == idx.end()) break;
                r[j] = *itr;
                itr++;
            }
        }
        {
            auto itr = idx.lower_bound(i);
            rep(j, 2) { // l
                if (itr == idx.begin()) break;
                itr--;
                l[j] = *itr;
            }
        }

        ll l1 = i - l[0], l2 = l[0] - l[1];
        ll r1 = r[0] - i, r2 = r[1] - r[0];
        ans += (l1 * r2 + l2 * r1) * now;

        idx.insert(i);
    }
    cout << ans << '\n';

    return 0;
}
