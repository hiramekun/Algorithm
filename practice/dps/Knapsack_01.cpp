//
// Created by Takaaki Hirano on 2018/08/06.
//
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1]; // i番目までの品物から重さの総和がj以下となるようにえらっbだ時の価値の総和の最大値

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    solve();
}

