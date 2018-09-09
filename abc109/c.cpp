#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)


const int MAX_N = (int) 1e5;
int N, X, x[MAX_N];

void solve() {
    if (N == 1) {
        cout << max(x[0] - X, X - x[0]) << endl;
        return;
    }
    sort(x, x + N);
    int diff = INF;
    int diffs[N - 1];
    FOR(i, 0, N - 1) {
        diff = min({x[i + 1] - x[i], diff, abs(X - x[i]), abs(X - x[i + 1])});
        diffs[i] = x[i + 1] - x[i];
    }
    REPR(d, diff) {
        REP(i, N - 1) {
            if (diffs[i] % (d + 1) != 0) break;
            if (i == N - 2) {
                cout << d + 1 << endl;
                return;
            }
        }
    }
}

int main() {
    cin >> N >> X;
    REP(i, N) cin >> x[i];
    solve();
    return 0;
}
