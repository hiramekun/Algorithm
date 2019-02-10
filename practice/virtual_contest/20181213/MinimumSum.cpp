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
typedef pair<int, int> P;
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

const int max_n = 2 * i_half_inf;
ll N, a[max_n];

void solve() {
    set<ll> sl, sr;
    ll ans = 0;
    rep(i, N) {
        rep(j, i) if (a[i] > a[j]) sl.insert(a[j]);
        FOR(j, i, N) if (a[i] > a[j]) sr.insert(a[j]);
        auto lower_l = sl.lower_bound(i);
        auto lower_r = sr.lower_bound(i);
        ll nl = (lower_l == sl.end()) ? i : *lower_l;
        ll nr = (lower_r == sr.end()) ? i : *lower_r;
        ans += a[i] * (nr + 1 - i) * (i + 1 - nl);
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    rep(i, N) cin >> a[i];
    solve();
    return 0;
}
