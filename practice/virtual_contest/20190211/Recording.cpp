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


ll n, c;
vector<pair<ll, ll>> cs[30];
ll num[30][half_inf];

void solve() {
    rep(i, c) sort(cs[i].begin(), cs[i].end());
    rep(i, c) {
        ll now = -1;
        rep(j, cs[i].size()) {
            if (now == cs[i][j].first) {
                for (ll k = cs[i][j].first + 1; k <= cs[i][j].second; k++) num[i][k]++;
            } else {
                for (ll k = cs[i][j].first; k <= cs[i][j].second; k++) num[i][k]++;
            }
            now = cs[i][j].second;
        }
    }
    ll ans = 0;
    rep(i, half_inf) {
        ll temp = 0;
        rep(j, c) temp += num[j][i];
        ans = max(temp, ans);
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> c;
    rep(i, n) {
        ll s, t, c;
        cin >> s >> t >> c;
        s--, t--, c--;
        cs[c].emplace_back(make_pair(s, t));
    }
    solve();
    return 0;
}
