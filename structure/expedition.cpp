#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
const int MAX_N = 10000;
int L, P, N;
int A[MAX_N + 1], B[MAX_N + 1];

void solve() {
    A[N] = L;
    B[N] = 0;
    N++;

    priority_queue<int> que;
    int ans = 0, pos = 0, tank = P;

    for (int i = 0; i < N; ++i) {
        int d = A[i] - pos;
        while (tank - d < 0) {
            if (que.empty()) {
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n", ans);
}

int main() {
    cin >> N >> L >> P;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    solve();
    return 0;
}
