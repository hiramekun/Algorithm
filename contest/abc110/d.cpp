#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

ll N, M;
const ll n_div = ll(1e9 + 7);
map<ll, ll> mp;


ll calc_divs(int n_select) {
    if (n_select == 1) return 1;
}

ll dfs(int idx) {
    if (idx == 1) return 1;
    return dfs(idx - 1) + calc_divs(idx);
}

void solve() {
    REPONE(i, M) if (M % i == 0) mp[i]++;
    ll dp[N];
    REP(i, N) {

    }
    EACH(v, mp) {
    }
}

int main() {
    cin >> N >> M;
    solve();
    return 0;
}
