//
// Created by Takaaki Hirano on 2018/08/16.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int MAX_M = 1000, MAX_N = 1000;
int n, m, M;
int dp[MAX_M + 1][MAX_N + 1];

void solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j - i >= 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[m][n]);
}

int main() {
    cin >> n >> m >> M;
    solve();
    return 0;
}
