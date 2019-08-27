/**
 * Created by hiramekun at 20:54 on 2019-08-27.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define all(obj) (obj).begin(), (obj).end()

using data = pair<ll, vl>;

int main() {

    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vl a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(all(a), greater<>()), sort(all(b), greater<>()), sort(all(c), greater<>());

    priority_queue<data> ans;
    set<data> used;
    ans.push(data(a[0] + b[0] + c[0], vl({0, 0, 0})));
    while (k-- > 0) {
        auto now = ans.top();
        ans.pop();
        cout << now.first << '\n';
        ll ia = now.second[0], ib = now.second[1], ic = now.second[2];

        data tmp;
        if (ia + 1 < a.size()) {
            tmp = data(a[ia + 1] + b[ib] + c[ic], vl({ia + 1, ib, ic}));
            if (used.find(tmp) == used.end()) {
                used.insert(tmp);
                ans.push(tmp);
            }
        }
        if (ib + 1 < b.size()) {
            tmp = data(a[ia] + b[ib + 1] + c[ic], vl({ia, ib + 1, ic}));
            if (used.find(tmp) == used.end()) {
                used.insert(tmp);
                ans.push(tmp);
            }
        }
        if (ic + 1 < c.size()) {
            tmp = data(a[ia] + b[ib] + c[ic + 1], vl({ia, ib, ic + 1}));
            if (used.find(tmp) == used.end()) {
                used.insert(tmp);
                ans.push(tmp);
            }
        }
    }
    return 0;
}
