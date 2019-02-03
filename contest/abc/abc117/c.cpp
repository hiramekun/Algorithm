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

ll n, m;
vector<ll> x;

void solve() {
    sort(x.begin(), x.end());
    ll diff[m - 1];
    rep(i, m - 1) diff[i] = abs(x[i + 1] - x[i]);
    sort(diff, diff + m - 1, greater<>());
    ll ans = 0;
    for (int j = n - 1; j < m - 1; ++j) {
        ans += diff[j];
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    x.resize(m);
    rep(i, m) cin >> x[i];
    solve();
    return 0;
}
