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

ll x, y;

void solve() {
    ll ans = ll_inf;
    if (-y >= -x)ans = min(ans, 1 - y + x + 1);
    if (y >= -x) ans = min(ans, 1 + y + x);
    if (-y >= x) ans = min(ans, 1 - y - x);
    if (y >= x) ans = min(ans, y - x);
    cout << ans << endl;
}

int main() {
    cin >> x >> y;
    solve();
    return 0;
}
