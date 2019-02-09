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

int n, m;
bool seen[1000][1000];

int rev(int x) {
    string tmp;
    each(s, to_string(x)) tmp = s + tmp;
    return stoi(tmp);
}

bool step(int &x, int &y) {
    if (x == 0 || y == 0) return false;
    if (x < y) x = rev(x);
    else y = rev(y);

    if (x < y) y -= x;
    else x -= y;
    return true;
}

void dfs(int x, int y) {
    int prex = x, prey = y;
    while (step(x, y) && !seen[x][y]) {
        seen[x][y] = true;
    }
}


void solve() {
    rep(i, n) rep(j, m) seen[i][j] = false;

    repone(i, n) dfs(i, 0);
    repone(i, m) dfs(0, i);
    ll ans = 0;
    rep(i, n) rep(j, m) if (!seen[i][j]) ans++;
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    solve();
    return 0;
}
