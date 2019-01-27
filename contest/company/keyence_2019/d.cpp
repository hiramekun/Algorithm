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
const ll mod = ll(1e9) + 7;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll n, m;
vector<ll> a, b;

void solve() {
    ll a_bigger[n], b_bigger[m];
    fill(a_bigger, a_bigger + n, 0);
    fill(b_bigger, b_bigger + m, 0);

    bool used[n * m];
    fill(used, used + n * m, false);
    rep(i, n) rep(j, m) if (a[i] >= b[j]) {
                a_bigger[i]++;
                used[a[i]] = true, used[b[j]] = true;
            }
    rep(i, m) rep(j, n) if (b[i] >= a[j]) b_bigger[i]++;
    ll c_used = 0;
    rep(i, n * m) if (!used[i]) c_used++;

    ll ans = 1;
    rep(i, n) {
        ans *= a_bigger[i], ans %= mod;
    }
    rep(i, m) {
        ans *= b_bigger[i], ans %= mod;
    }
    repone(i, n * m - c_used) ans *= i, ans %= mod;
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    a.resize(n), b.resize(m);
    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];
    solve();
    return 0;
}
