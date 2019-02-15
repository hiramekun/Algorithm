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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll n, k;
map<ll, ll> mp;

void solve() {
    ll c = 0;
    each(m, mp) {
        if (m.second + c >= k) {
            cout << m.first << endl;
            return;
        } else {
            c += m.second;
        }
    }
}

int main() {
    cin >> n >> k;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    solve();
    return 0;
}
