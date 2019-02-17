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
    ll n, m;
    vector<ll> a, b, c, d;
    cin >> n >> m;
    a.resize(n), b.resize(n), c.resize(m), d.resize(m);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];

    ll ans[n];
    rep(i, n) {
        ll tmp = ll_inf;
        rep(j, m) {
            if (abs(a[i] - c[j]) + abs(b[i] - d[j]) < tmp) {
                tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
                ans[i] = j + 1;
            }
        }
        cout << ans[i] << endl;
    }
    return 0;
}
