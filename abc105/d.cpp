//
// Created by Takaaki Hirano on 2018/08/11.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
const int MAX_N = 100000;
long long N, M, A[MAX_N];
long long dp[MAX_N + 1];

void solve() {
    long long res = 0;
    map<long long, long long> mp;

    for (int i = 0; i < N; i++) {
        dp[i + 1] = (dp[i] + A[i]) % M;
        mp[dp[i + 1]] = mp[dp[i + 1]] + 1;
    }

    for (auto const &val: mp) {
        res += val.second * (val.second - 1) / 2;
        if (val.first == 0) {
            res += val.second;
        }
    }

    printf("%lld\n", res);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] = A[i] % M;
    }
    solve();
    return 0;
}
