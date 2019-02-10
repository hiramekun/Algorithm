//
// Created by Takaaki Hirano on 2018/08/11.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_Q = 150, MAX_X = 1000;
int q, dp[MAX_X + 1][MAX_X + 1];
string x[MAX_X], y[MAX_X];

void solve() {
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < x[i].length(); j++) {
            for (int k = 0; k < y[i].length(); k++) {
                if (x[i][j] == y[i][k]) {
                    dp[j + 1][k + 1] = dp[j][k] + 1;
                } else {
                    dp[j + 1][k + 1] = max(dp[j][k + 1], dp[j + 1][k]);
                }
            }
        }
        cout << dp[x[i].length()][y[i].length()] << endl;
    }
}

int main() {
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
    }
    solve();
    return 0;
}
