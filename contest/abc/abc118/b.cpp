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


int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<ll, ll> mp;
    rep(i, n) {
        int k;
        cin >> k;
        ll a[k];
        rep(j, k) {
            cin >> a[j];
            mp[a[j]]++;
        }
    }
    ll ans = 0;
    each(s, mp) {
        if (s.second == n) ans++;
    }
    cout << ans << endl;
    return 0;
}
