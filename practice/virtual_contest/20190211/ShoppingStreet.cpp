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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

const int max_n = 100;
const int ten = 10;
ll f[max_n][ten];
ll p[max_n][ten + 1];
ll n;

void solve() {
    ll ans = -inf;
    for (int i = 1; i < pow(2, ten); ++i) {
        ll same_time_count[n];
        fill(same_time_count, same_time_count + n, 0);
        rep(j, ten) {
            if ((1 & i >> j) == 1) {
                rep(k, n) if (f[k][j] == 1) same_time_count[k]++;
            }
        }
        ll temp = 0;
        rep(k, n) temp += p[k][same_time_count[k]];
        ans = max(temp, ans);
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    rep(i, n) rep(j, 10) cin >> f[i][j];
    rep(i, n) rep(j, 11) cin >> p[i][j];
    solve();
    return 0;
}
