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
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int MAX_N = 4;
int N, t[MAX_N];

void solve() {
    int ans = INF;
    REP(i, pow(2, N)) {
        int sum1 = 0, sum2 = 0;
        REP(j, N) {
            if ((1 & i >> j) == 1) sum1 += t[j];
            else sum2 += t[j];
        }
        ans = min(max(sum1, sum2), ans);
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> t[i];
    solve();
    return 0;
}
