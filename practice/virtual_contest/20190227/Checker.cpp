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
ll n, k;
vector<ll> x, y;
vector<char> c;

void solve() {
    ll d_b[2 * k][2 * k], d_w[2 * k][2 * k];
    rep(i, 2 * k) rep(j, 2 * k) d_b[i][j] = d_w[i][j] = 0;
    rep(i, n) {
        if (c[i] == 'B') {
            d_b[x[i] % (2 * k)][y[i] % (2 * k)]++;
        } else if (c[i] == 'W') {
            d_w[x[i] % (2 * k)][y[i] % (2 * k)]++;
        }
    }
    rep(i, 2 * k) {
        repone(j, 2 * k - 1) {
            d_b[i][j] = d_b[i][j - 1] + d_b[i][j];
            d_w[i][j] = d_w[i][j - 1] + d_w[i][j];
        }
    }
    rep(j, 2 * k) {
        repone(i, 2 * k - 1) {
            d_b[i][j] = d_b[i - 1][j] + d_b[i][j];
            d_w[i][j] = d_w[i - 1][j] + d_w[i][j];
        }
    }
    rep(i, 2 * k) {
        rep(j, 2 * k) {
        }
    }
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> n >> k;
        x.resize(n), y.resize(n), c.resize(n);
        rep(i, n) cin >> x[i] >> y[i] >> c[i];
        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}