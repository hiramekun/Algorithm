#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
//typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 100;
ll N, F[MAX_N][10], P[MAX_N][11];

void solve() {
    const int n = 10;
    ll ans = -INF;
    REP(i, pow(2, n)) {
        if (i == 0) continue;
        ll sum = 0;
        REP(k, N) {
            int c_open = 0;
            REP(j, n) if ((1 & i >> j) == 1 && F[k][j] == 1) c_open++;
            sum += P[k][c_open];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    REP(i, N) REP(j, 10) cin >> F[i][j];
    REP(i, N) REP(j, 11) cin >> P[i][j];
    solve();
    return 0;
}
