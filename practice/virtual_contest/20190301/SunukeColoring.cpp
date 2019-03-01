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
typedef map<pair<ll, ll>, ll> ump;
typedef pair<ll, ll> P;

ump mp;
ll h, w, n;

void solve() {
    map<int, ll> ans;
    set<pair<ll, ll>> see;
    each(m, mp) {
        ll x = m.first.first;
        ll y = m.first.second;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nx = x + i, ny = y + j;
                if (nx >= 1 && ny >= 1 && nx <= h - 2 && ny <= w - 2) {
                    see.insert(make_pair(nx, ny));
                }
            }
        }
    }
    each(s, see) {
        ll x = s.first;
        ll y = s.second;
        ll tmp = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nx = x + i, ny = y + j;
                tmp += mp[make_pair(nx, ny)];
            }
        }
        ans[tmp]++;
    }
    ans[0] = (h - 2) * (w - 2) - see.size();
    rep(i, 10) cout << ans[i] << endl;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> h >> w >> n;
        rep(i, n) {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            mp[make_pair(a, b)]++;
        }

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}