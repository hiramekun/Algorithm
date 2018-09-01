//
// Created by Takaaki Hirano on 2018/09/01.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
int N, K;
long long ans = 0;

void solve() {
    unordered_map<long long, long long> mp;
    // あまりを保持しておく
    for (int i = 1; i <= N; ++i) mp[i % K]++;

    // 全てのaに対して
    for (int a = 1; a <= N; ++a) {
        // aに対するb, cのあまり（等しくなる）
        int b = (K - a % K) % K;
        int c = (K - a % K) % K;

        // 場合の数を数えるためにあまりの場合の数を求める．
        if ((b + c) % K == 0) ans += mp[b] * mp[c];
    }

    printf("%lli\n", ans);
}

int main() {
    cin >> N >> K;
    solve();
    return 0;
}
