//
// Created by Takaaki Hirano on 2018/09/05.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)


const int MAX_N = (int) 1e5;
ll N, C, x[MAX_N], v[MAX_N], dp[MAX_N + 1], dpr[MAX_N + 1];

void solve() {
    ll ans = 0;
    REP(i, N) {
        REP(j, N - i) {
            ll oa = dp[i + 1] - x[i];
            ll ob = dpr[j + 1] - (C - x[N - j]);
            ll ab = dp[i + 1] + dpr[j + 1] - 2 * x[i] - (C - x[N - j]);
            ll ba = dp[i + 1] + dpr[j + 1] - 2 * (C - x[N - j]) - x[i];
            ans = max({ans, oa, ob, ab, ba});
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> C;
    REP(i, N) {
        cin >> x[i] >> v[i];
        dp[i + 1] = dp[i] + v[i];
    }
    REP(i, N) {
        dpr[i + 1] = dpr[i] + v[N - i];
    }
    solve();
    return 0;
}

