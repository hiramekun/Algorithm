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
#define i_INF int(1e9)
#define ll_INF ll(1e9) * ll(1e9)
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll x, y;

void solve() {
    ll ans = ll_INF;
    if (y >= x) {
        ans = min(ans, abs(y - x));
    }
    if (-y >= -x) {
        ans = min(ans, abs(-y - (-x)) + 2);
    }
    if (y >= -x) {
        ans = min(ans, abs(y - (-x)) + 1);
    }
    if (-y >= x) {
        ans = min(ans, abs(-y - x) + 1);
    }
    cout << ans << endl;
}

int main() {
    cin >> x >> y;
    solve();
    return 0;
}
