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
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = int(1e5);
ll N;
unordered_map<ll, ll> mp;


void solve() {
    ll ans = 1;
    REP(i, N / 2) {
        ans *= 2;
        ans %= ll(1e9 + 7);
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    ll temp;
    REP(i, N) {
        cin >> temp;
        mp[temp]++;
        if (mp[temp] > 2 || mp[0] == 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    solve();
    return 0;
}