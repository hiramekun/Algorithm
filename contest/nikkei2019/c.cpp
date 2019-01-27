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
struct dish {
    ll a, b;
    ll idx;
};
vector<dish> ds;

void solve() {
    sort(ds.begin(), ds.end(), [](dish d1, dish d2) {
        if (d1.a == d2.a) return d1.b > d2.b;
        else return d1.a > d2.a;
    });
    vector<dish> ds_c(ds);
    sort(ds_c.begin(), ds_c.end(), [](dish d1, dish d2) {
        if (d1.b == d2.b) return d1.a > d2.a;
        else return d1.b > d2.b;
    });
    ll ans = 0;
    unordered_map<ll, ll> used;
    ll idx_t = 0, idx_a = 0;

    while (idx_t < n || idx_a < n) {
        while (idx_t < n - 1 && used[ds[idx_t].idx] == 1) idx_t++;
        if (used[ds[idx_t].idx] == 0) {
            ans += ds[idx_t].a;
            used[ds[idx_t].idx]++;
        } else break;
        idx_t++;

        while (idx_a < n - 1 && used[ds_c[idx_a].idx] == 1) idx_a++;
        if (used[ds_c[idx_a].idx] == 0) {
            ans -= ds_c[idx_a].b;
            used[ds_c[idx_a].idx]++;
        }
        idx_a++;
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    ds.resize(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        dish d = {a, b, i};
        ds[i] = d;
    }
    solve();
    return 0;
}
