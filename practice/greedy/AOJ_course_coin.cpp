//
// Created by Takaaki Hirano on 2018/07/31.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 50000, MAX_M = 20;

int n, m;
int C[MAX_M];

void solve() {
    sort(C, C + m);

    int ans = 0;
    for (int i = m - 1; i >= 0; i--) {
        int temp = n / C[i];
        n -= C[i] * temp;
        ans += temp;
    }
    printf("%d\n", ans);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> C[i];
    }
    solve();
    return 0;
}
