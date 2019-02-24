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
int n, a, b, c;
vector<int> l;
ll ans;

void dfs(ll len_a, ll len_b, ll len_c, ll idx, ll mp) {
    if (idx == n) {
        if (len_a * len_b * len_c == 0) return;
        ans = min(ans, mp + abs(len_a - a) + abs(len_b - b) + abs(len_c - c));
        return;
    }
    dfs(len_a + l[idx], len_b, len_c, idx + 1, len_a == 0 ? mp : mp + 10);
    dfs(len_a, len_b + l[idx], len_c, idx + 1, len_b == 0 ? mp : mp + 10);
    dfs(len_a, len_b, len_c + l[idx], idx + 1, len_c == 0 ? mp : mp + 10);
    dfs(len_a, len_b, len_c, idx + 1, mp);
}


void solve() {
    ans = ll_inf;
    dfs(0, 0, 0, 0, 0);
    cout << ans << endl;
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> n >> a >> b >> c;
        l.resize(n);
        rep(i, n) cin >> l[i];

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}