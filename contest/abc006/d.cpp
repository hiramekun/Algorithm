//
// Created by Takaaki Hirano on 2018/08/11.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 3 * 10000;
int N, c[MAX_N], dp[MAX_N];

void solve() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (c[j] < c[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        res = max(res, dp[i]);
    }

    printf("%d\n", N - res);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    solve();
    return 0;
}
