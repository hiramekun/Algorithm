#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_W = 10000, MAX_N = 50, MAX_K = 50;
vector<pair<int, int> > ab_pairs;

int W, N, K;
int dp[MAX_N + 1][MAX_K + 1][MAX_W + 1];

void solve() {
    int a, b, ans = 0;
    for (int i = 0; i < N; i++) {
        a = ab_pairs[i].first;  // 幅
        b = ab_pairs[i].second; // 重要度

        for (int h = 0; h < K; h++) {
            for (int j = 0; j <= W; j++) {
                if (j < a) {
                    dp[i + 1][h][j] = dp[i][h][j];
                    ans = max(dp[i + 1][h][j], ans);

                } else {
                    dp[i + 1][h + 1][j] = max(dp[i][h + 1][j], dp[i][h][j - a] + b);
                    ans = max(dp[i + 1][h + 1][j], ans);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    cin >> W >> N >> K;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        ab_pairs.emplace_back(make_pair(a, b));
    }
    solve();
}
