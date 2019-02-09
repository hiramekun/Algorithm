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

const int max_size = 2 * int(1e3);
char s[max_size][max_size];
int n, m;

void solve() {
    ll up[n][m], left[n][m];
    ll down[n][m], right[n][m];
    rep(i, n) rep(j, m) up[i][j] = -1, left[i][j] = -1, down[i][j] = -1, right[i][j] = -1;

    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == '.') {
                if (i == 0) up[i][j] = 0;
                else up[i][j] = up[i - 1][j] + 1;

                if (j == 0) left[i][j] = 0;
                else left[i][j] = left[i][j - 1] + 1;
            }
        }
    }

    repr(i, n) {
        repr(j, m) {
            if (s[i][j] == '.') {
                if (i == n - 1) down[i][j] = 0;
                else down[i][j] = down[i + 1][j] + 1;

                if (j == m - 1) right[i][j] = 0;
                else right[i][j] = right[i][j + 1] + 1;
            }
        }
    }

    ll ans = 0;
    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == '.')
                ans += (down[i][j] * right[i][j] + right[i][j] * up[i][j] + up[i][j] * left[i][j] +
                        left[i][j] * down[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> s[i][j];
    solve();
    return 0;
}
