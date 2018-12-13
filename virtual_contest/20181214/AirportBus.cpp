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

const int max_n = i_half_inf;
ll n, c, k, t[max_n];

void solve() {
    sort(t, t + n);
    ll ans = 1, c_temp = 0, t_first = t[0];
    rep(i, n) {
        if (t[i] > t_first + k || c_temp == c) {
            c_temp = 1;
            t_first = t[i];
            ans++;
        } else c_temp++;
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> c >> k;
    rep(i, n) cin >> t[i];
    solve();
    return 0;
}
