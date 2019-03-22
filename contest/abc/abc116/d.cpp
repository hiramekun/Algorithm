#include <cstring>
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
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
ll n, k;
vector<P> dt;
map<ll, ll> max_mp;
bool used[half_inf];
priority_queue<ll, vector<ll>, greater<>> others;

void solve() {
    sort(dt.begin(), dt.end(), greater<>());

    ll ans = 0;
    ll tmp = 0, tmp2 = 0;
    rep(i, k) {
        if (!used[dt[i].second] && dt[i].first == max_mp[dt[i].second]) {
            tmp++;
            used[dt[i].second] = true;
        } else {
            others.push(dt[i].first);
        }
        ans += dt[i].first;
        tmp2 += dt[i].first;
    }
    ans += tmp * tmp;
    vector<pair<ll, ll> > v(max_mp.begin(), max_mp.end());

    // sort from bigger.
    sort(v.begin(), v.end(),
         [](pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; });

    each(m, v) {
        if (used[m.first]) continue;
        if (others.empty()) break;
        ll minus = others.top();
        others.pop();
        tmp++;

        tmp2 = tmp2 - minus + m.second;
        ans = max(tmp2 + tmp * tmp, ans);
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> k;
    dt.resize(n);
    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        dt[i] = make_pair(d, t);
        max_mp[dt[i].second] = max(max_mp[dt[i].second], dt[i].first);
    }
    solve();
    return 0;
}
