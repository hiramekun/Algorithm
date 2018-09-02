#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF (1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int MAX_N = int(1e5);
ll N, M, A[MAX_N];


void solve() {
    unordered_map<ll, ll> mp;
    ll ans = 0;
    ll dp[MAX_N + 1];
    REP(i, N) {
        dp[i + 1] = (dp[i] + A[i]) % M;
        mp[dp[i + 1]] = mp[dp[i + 1]] + 1;
    }
    each(mod, mp) {
        ans += mod.second * (mod.second - 1) / 2;
        if (mod.first == 0) ans += mod.second;
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> A[i];
    solve();
    return 0;
}
