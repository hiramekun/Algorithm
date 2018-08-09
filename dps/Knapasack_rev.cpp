//
// Created by Takaaki Hirano on 2018/08/09.
//
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 100, MAX_W = 10000000, INF = 1000000000, MAX_V = 100;
int n, W, v[MAX_V], w[MAX_W];
int dp[MAX_N + 1][MAX_N * MAX_V + 1];

void solve() {
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= MAX_N * MAX_V; j++) {
            if (j < v[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= MAX_N * MAX_V; i++) if (dp[n][i] <= W) res = i;
    printf("%d\n", res);
}

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    solve();
}
