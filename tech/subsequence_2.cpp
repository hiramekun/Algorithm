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

void solve() {
    int res = n + 1;
    int s = 0, t = 0, sum = 0;
    for (;;) {
        while (t < n && sum < S) sum += a[t++];
        if (sum < S) break;
        res = min(res, t - s);
        sum -= a[s++];
    }

    if (res > n) res = 0;
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
