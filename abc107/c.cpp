#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int MAX_N = 100000;
const int INF = 1000000000;
int N, K;
int xs[MAX_N];

void solve() {
    int ans = INF;
    for (int i = 0; i < N - K + 1; ++i) {
        int x_min = xs[i], x_max = xs[i + K - 1];
        ans = min(ans, min(abs(x_min) + x_max - x_min, abs(x_max) + x_max - x_min));
    }
    printf("%d", ans);
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> xs[i];
    }
    solve();
    return 0;
}
