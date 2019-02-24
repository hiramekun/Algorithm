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
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;

void solve() {
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n, C;
        cin >> n >> C;
        ll D[C][C];
        rep(i, C) rep(j, C) cin >> D[i][j];
        ll c[n][n];
        ll c_count[3][C];
        rep(i, 3) rep(j, C) c_count[i][j] = 0;
        rep(i, n) {
            rep(j, n) {
                cin >> c[i][j], c[i][j]--;
                c_count[(i + 1 + j + 1) % 3][c[i][j]]++;
            }
        }

        ll ans = ll_inf;
        rep(k, C) {
            rep(l, C) {
                if (k == l) continue;
                rep(m, C) {
                    if (l == m || m == k) continue;
                    ll temp = 0;
                    rep(i, C) temp += D[i][k] * c_count[0][i];
                    rep(i, C) temp += D[i][l] * c_count[1][i];
                    rep(i, C) temp += D[i][m] * c_count[2][i];
                    ans = min(temp, ans);
                }
            }
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}
