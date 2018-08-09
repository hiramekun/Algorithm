//
// n種類のa_iがそれぞれm_i個ずつあります。
// こららの中からいくつか選び、その総和をちょうど
// Kとすることができるか判定しなさい。
// 1 <= n <= 100, 1 <= a_i, m_i <= 100000, 1 <= K <= 100000
//
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 100, MAX_K = 100000;
int n, K, a[MAX_N], m[MAX_N];

// dp[i+1][j] = i番目まででjを作る際に余る最大のi番目の個数（作れない場合-1）
int dp[MAX_K + 1];

void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }

    if (dp[K] >= 0) printf("Yes\n");
    else printf("No\n");
}

int main() {
    cin >> n >> K;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> m[i];
    }
    solve();
}

