#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
int N;

void solve() {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) continue;
        int count = 0;
        for (int j = 1; j <= N; ++j) {
            if (i % j == 0) count++;
        }
        if (count == 8) ans++;
    }
    printf("%d\n", ans);
}

int main() {
    cin >> N;
    solve();
    return 0;
}

