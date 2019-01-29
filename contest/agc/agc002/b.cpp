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
vector<pair<ll, ll>> xy;

void solve() {
    unordered_map<ll, ll> mp;
    rep(i, n) mp[i]++;
    set<ll> idx_red;
    idx_red.insert(0);
    rep(i, m) {
        ll x = xy[i].first, y = xy[i].second;
        if (idx_red.count(x) != 0) {
            if (mp[x] == 1) idx_red.erase(x);
            idx_red.insert(y);
        }
        mp[x]--, mp[y]++;
    }
    cout << idx_red.size() << endl;
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        xy.emplace_back(make_pair(x, y));
    }
    solve();
    return 0;
}
