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

    // 全てのあまりに対して
    for (auto a_mod: mp) {
        long long b = (K - a_mod.first) % K;
        long long c = (K - a_mod.first) % K;

        // 場合の数を数えるためにあまりの場合の数を求める．
        if ((b + c) % K == 0) ans += a_mod.second * mp[b] * mp[c];
    }

    printf("%lli\n", ans);
}

int main() {
    cin >> N >> K;
    solve();
    return 0;
}
