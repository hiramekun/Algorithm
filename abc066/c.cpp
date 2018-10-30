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

const int MAX_N = 2 * int(1e5);
int n;
ll a[MAX_N];

void solve() {
    ll b[n];
    REP(i, n) {
        if (i % 2 == 0) b[i / 2] = a[n - 1 - i];
        else b[n - 1 - i / 2] = a[n - 1 - i];
    }
    REP(i, n) printf("%lli ", b[i]);
}

int main() {
    cin >> n;
    REP(i, n) cin >> a[i];
    solve();
    return 0;
}
