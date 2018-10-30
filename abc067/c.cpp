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
typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int N;
const int MAX_N = 2 * int(1e5);
ll a[MAX_N], dp[MAX_N];

void solve() {
    ll ans = ll(5) * INF;
    REP(i, N - 1) ans = min(ans, abs(dp[i] - (dp[N - 1] - dp[i])));
    cout << ans << endl;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> a[i];
        if (i == 0) dp[0] = a[0];
        else dp[i] = dp[i - 1] + a[i];
    }
    solve();
    return 0;
}
