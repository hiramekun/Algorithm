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
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N, A, B, K;

ll multi(ll i) {
    if (i == 1) return 1;
    return i * multi(i - 1);
}

void solve() {
    ll ans = 0;
    ll multi_n = multi(N);
    if (K == 0) {
        cout << 1 << endl;
        return;
    }
    REPONE(i, N) {
        ll b = (K - A * i) / B;
        if (A * i + B * b != K) continue;
        ans += (multi_n / ((multi(i) * multi(N - i))) * multi_n / ((multi(b) * multi(N - b)))) %
               998244353;
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> A >> B >> K;
    solve();
    return 0;
}
