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

ll n;
vector<pair<ll, ll>> ab;

void solve() {
    // sort from bigger.
    sort(ab.begin(), ab.end(),
         [](pair<ll, ll> a, pair<ll, ll> b) { return a.first + a.second > b.first + b.second; });
    ll ans = 0;
    rep(i, n) {
        if (i % 2 == 0) ans += ab[i].first;
        else ans -= ab[i].second;
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ab.emplace_back(make_pair(a, b));
    }
    solve();
    return 0;
}
