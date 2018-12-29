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

const int MAX_N = (int) 1e5;
ll N, x;
ll a[MAX_N];

void solve() {
    ll ans = 0;
    if (a[0] > x) {
        ans += (a[0] - x);
        a[0] = x;
    }
    REP(i, N - 1) {
        if (a[i] + a[i + 1] > x) {
            ll temp = min(a[i + 1], a[i] + a[i + 1] - x);
            a[i + 1] -= temp;
            ans += temp;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> x;
    REP(i, N) cin >> a[i];
    solve();
    return 0;
}
