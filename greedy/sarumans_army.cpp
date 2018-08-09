//
// Created by Takaaki Hirano on 2018/08/02.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 0;
int N, R;
int X[MAX_N];

void solve() {
    sort(X, X + N);

    int i = 0, ans = 0;
    while (i < N) {
        int s = X[i++];
        while (i < N && X[i] <= s + R) i++;

        int p = X[i - 1];

        while (i < N && X[i] <= p + R) i++;

        ans++;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
}

