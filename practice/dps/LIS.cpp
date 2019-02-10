//
// Created by Takaaki Hirano on 2018/08/11.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 1000;
int n, a[MAX_N], dp[MAX_N];

void solve() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    printf("%d\n", res);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
    return 0;
}
