//
// Created by Takaaki Hirano on 2018/08/09.
//
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100, MAX_W = 10000;
int N, W;
int dp[MAX_N + 1][MAX_W + 1];
int w[MAX_N], v[MAX_N];

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[N][W]);
}

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }
    solve();
}
