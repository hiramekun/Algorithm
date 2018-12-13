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
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll ans = 0;
ll n;

void dfs(string num, bool a, bool b, bool c) {
    if (stol(num) > n) return;
    if (a && b && c) ans++;
    dfs(num + '3', true, b, c);
    dfs(num + '5', a, true, c);
    dfs(num + '7', a, b, true);
}

void solve() {
    dfs("3", true, false, false);
    dfs("5", false, true, false);
    dfs("7", false, false, true);
    cout << ans << endl;
}

int main() {
    cin >> n;
    solve();
    return 0;
}
