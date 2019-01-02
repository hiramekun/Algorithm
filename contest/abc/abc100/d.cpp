#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll n, m;
struct cake {
    ll x, y, z;
};
vector<cake> c;
ll dp[1000];

ll calc(vector<cake> v) {
    ll retx = 0, rety = 0, retz = 0;
    rep(i, m) retx += c[i].x, rety += c[i].y, retz += c[i].z;
    return abs(retx) + abs(rety) + abs(retz);
}

void solve() {
    ll ans = 0;
    sort(c.begin(), c.end(), [](cake a, cake b) { return a.x + a.y + a.z > b.x + b.y + b.z; });
    ans = max(calc(c), ans);
    sort(c.begin(), c.end(), [](cake a, cake b) { return a.x + a.y - a.z > b.x + b.y - b.z; });
    ans = max(calc(c), ans);
    sort(c.begin(), c.end(), [](cake a, cake b) { return a.x - a.y + a.z > b.x - b.y + b.z; });
    ans = max(calc(c), ans);
    sort(c.begin(), c.end(), [](cake a, cake b) { return -a.x + a.y + a.z > -b.x + b.y + b.z; });
    ans = max(calc(c), ans);
    sort(c.begin(), c.end(), [](cake a, cake b) { return -a.x - a.y + a.z > -b.x - b.y + b.z; });
    ans = max(calc(c), ans);
    sort(c.begin(), c.end(), [](cake a, cake b) { return -a.x + a.y - a.z > -b.x + b.y - b.z; });
    ans = max(calc(c), ans);
    sort(c.begin(), c.end(), [](cake a, cake b) { return a.x - a.y - a.z > b.x - b.y - b.z; });
    ans = max(calc(c), ans);
    sort(c.begin(), c.end(), [](cake a, cake b) { return -a.x - a.y - a.z > -b.x - b.y - b.z; });
    ans = max(calc(c), ans);
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    c.resize(n);
    rep(i, n) {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        c[i] = {t1, t2, t3};
    }
    solve();
    return 0;
}
