#include <cstdio>
#include <cstring>
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
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = int(1e5);
ll n, a[MAX_N], dp[MAX_N], dp1[MAX_N];

void solve() {
    ll even_plus = 0, even_minus = 0;
    ll diffs = 0;
    REP(i, n) {
        ll diff = 0;
        dp1[i] += diffs;
        if (i % 2 == 0 && dp1[i] <= 0) {
            diff = 1 - dp1[i];
            diffs += diff;
            dp1[i] = 1;
        } else if (i % 2 != 0 && dp1[i] >= 0) {
            diff = -1 - dp1[i];
            diffs += diff;
            dp1[i] = -1;
        }
        even_plus += abs(diff);
    }
    diffs = 0;
    REP(i, n) {
        ll diff = 0;
        dp[i] += diffs;
        if (i % 2 == 0 && dp[i] >= 0) {
            diff = -1 - dp[i];
            diffs += diff;
            dp[i] = -1;
        } else if (i % 2 != 0 && dp[i] <= 0) {
            diff = 1 - dp[i];
            diffs += diff;
            dp[i] = 1;
        }
        even_minus += abs(diff);
    }
    cout << (even_minus < even_plus ? even_minus : even_plus) << endl;
}

int main() {
    cin >> n;
    REP(i, n) {
        cin >> a[i];
        if (i == 0) dp[0] = a[0];
        else dp[i] = dp[i - 1] + a[i];
    }
    memcpy(dp1, dp, sizeof(dp));
    solve();
    return 0;
}
