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

ll h, w;
char a[8][8];
bool seen[8][8];

bool dfs(int i, int j) {
    seen[i][j] = true;
    if (i - 1 >= 0 && a[i - 1][j] == '#' && !seen[i - 1][j]) return false;
    if (j - 1 >= 0 && a[i][j - 1] == '#' && !seen[i][j - 1]) return false;
    if (i == h - 1 && j == w - 1) return true;

    if (i + 1 <= h - 1 && a[i + 1][j] == '#' && j + 1 <= w - 1 && a[i][j + 1] == '#')
        return false;
    if (i + 1 <= h - 1 && a[i + 1][j] == '#') if (dfs(i + 1, j)) return true;
    if (j + 1 <= w - 1 && a[i][j + 1] == '#') if (dfs(i, j + 1)) return true;
    return false;
}

void solve() {
    fill(seen[0], seen[8], false);
    if (dfs(0, 0)) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}

int main() {
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> a[i][j];
    solve();
    return 0;
}
