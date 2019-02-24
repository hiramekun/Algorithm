#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;
ll a, b, q;
vector<ll> s, t, x;

void solve() {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    rep(i, q) {
        auto s_b = lower_bound(s.begin(), s.end(), x[i]);
        auto t_b = lower_bound(t.begin(), t.end(), x[i]);

        ll l_s = *s_b, l_t = *t_b;
        ll s_pre = *(s_b - 1), t_pre = *(t_b - 1);
        ll ans = ll_inf;
        ans = min({ans,
                   max(l_s - x[i], l_t - x[i]),
                   min(x[i] - s_pre, l_t - x[i]) * 2 + max(x[i] - s_pre, l_t - x[i]),
                   min(x[i] - t_pre, l_s - x[i]) * 2 + max(x[i] - t_pre, l_s - x[i]),
                   max(x[i] - s_pre, x[i] - t_pre)
                  });
        cout << ans << endl;
    }
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> a >> b >> q;
        s.resize(a), t.resize(b), x.resize(q);
        rep(i, a) cin >> s[i];
        rep(i, b) cin >> t[i];
        rep(i, q) cin >> x[i];
        s.emplace_back(ll_inf);
        s.emplace_back(-ll_inf);
        t.emplace_back(-ll_inf);
        t.emplace_back(ll_inf);
        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}