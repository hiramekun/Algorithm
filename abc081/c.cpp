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
ll K, N, A[MAX_N];
unordered_map<ll, ll> mp;

void solve() {
    vector<pair<ll, ll> > v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });
    ll ans = 0;
    REP(i, v.size() - K) ans += v[i].second;
    cout << ans << endl;
}

int main() {
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
        mp[A[i]]++;
    }
    solve();
    return 0;
}
