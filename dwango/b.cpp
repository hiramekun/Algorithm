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
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 1000;
ll N, K, a[MAX_N];
vector<ll> partial;

void solve() {
    REP(i, N) {
        ll prev = a[i];
        partial.emplace_back(prev);
        FOR(j, i, N) {
            if (j == i) continue;
            prev += a[j];
            partial.emplace_back(prev);
        }
    }
    sort(partial.begin(), partial.end());
    ll ans = -1;
    REPONE(i, K) {
        if (ans == -1) ans = partial[partial.size() - i];
        else ans = (ans & partial[partial.size() - i]);
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> a[i];
    solve();
    return 0;

}
