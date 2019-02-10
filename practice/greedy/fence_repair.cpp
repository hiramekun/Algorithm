//
// Created by Takaaki Hirano on 2018/08/02.
//
#include <cstdio>
#include <algorithm>

typedef long long ll;
const int MAX_N = 1;
int N, L[MAX_N];

using namespace std;

void solve() {
    ll ans = 0;

    while (N > 1) {
        int mii1 = 0, mii2 = 1;
        if (L[mii1] > L[mii2]) swap(mii1, mii2);

        for (int i = 2; i < N; i++) {
            if (L[i] < L[mii1]) {
                mii2 = mii1;
                mii1 = i;
            } else if (L[i] < L[mii2]) {
                mii2 = i;
            }
        }

        int t = L[mii1] + L[mii2];
        ans += t;

        if (mii1 == N - 1) swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[N - 1];
        N--;
    }

    printf("%lld\n", ans);
}

int main() {
    solve();
}

