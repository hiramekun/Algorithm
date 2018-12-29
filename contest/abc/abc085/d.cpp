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

ll n, h;
vector<ll> a, b;

void solve() {
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end());
    auto bound = lower_bound(b.begin(), b.end(), a[0]);
    ll ans = 0;
    for (auto i = b.end() - 1; i >= bound; --i) {
        h -= *i;
        ans++;
        if (h <= 0) break;
    }
    if (h > 0) ans += (h % a[0] == 0 ? h / a[0] : (h / a[0] + 1));
    cout << ans << endl;
}

int main() {
    cin >> n >> h;
    a.resize(n);
    b.resize(n);
    rep(i, n) cin >> a[i] >> b[i];
    solve();
    return 0;
}
