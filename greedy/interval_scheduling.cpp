//
// Created by Takaaki Hirano on 2018/07/31.
//
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int N, S[MAX_N], T[MAX_N];

pair<int, int> itv[MAX_N];

void solve() {
    for (int i = 0; i < N; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + N);

    int ans = 0, t = 0;
    for (int i = 0; i < N; i++) {
        if (t < itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }

    printf("%d\n", ans);
}
