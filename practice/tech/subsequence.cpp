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

const int MAX_N = int(1e5);
int n, S, a[MAX_N];
int sum[MAX_N + 1];

void solve() {
    if (sum[n] < S) {
        cout << "0" << endl;
        return;
    }
    int res = n;
    for (int s = 0; sum[s] + S <= sum[n]; s++) {
        int t = int(lower_bound(sum + s, sum + n, sum[s] + S) - sum);
        res = min(res, t - s);
    }
    cout << res << endl;
}

int main() {
    cin >> n >> S;
    REP(i, n) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    solve();
    return 0;
}
