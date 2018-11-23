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
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const ll MAX_N = ll(1e5);
ll N, a[MAX_N * 3];

void solve() {
    ll ans = 0;
    sort(a, a + 3 * N);
    for (ll i = 3 * N - 2; i >= N; i -= 2) ans += a[i];
    cout << ans << endl;
}

int main() {
    cin >> N;
    REP(i, 3 * N) cin >> a[i];
    solve();
    return 0;
}
