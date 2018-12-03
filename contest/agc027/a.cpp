#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int MAX_N = 100;
ll N, x, a[MAX_N], dp[MAX_N + 1];

void solve() {
    sort(a, a + N);
    ll ans = 0, res = x;
    REP(i, N) {
        if (i == N - 1) {
            if (res - a[i] == 0) {
                ans++;
                break;
            } else {
                break;
            }
        }
        if (res >= a[i]) {
            ans++;
            res -= a[i];
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> x;
    dp[0] = 0;
    REP(i, N) cin >> a[i];
    solve();
    return 0;
}
