//
// Created by Takaaki Hirano on 2018/07/31.
//

#include <cstdio>
#include <iostream>

using namespace std;

int T;
int V[6] = {500, 100, 50, 10, 5, 1};

void solve() {
    int P = 1000 - T;
    int ans = 0;

    for (int i : V) {
        int temp = (P / i);
        P -= i * temp;
        ans += temp;
    }
    printf("%d\n", ans);
}

int main() {
    cin >> T;
    solve();
    return 0;
}
