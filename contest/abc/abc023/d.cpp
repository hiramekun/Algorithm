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
vector<ll> h, s;

void solve() {
    ll p_s = 0, p_e = ll(1e14);
    LOOP:;
    while (p_e - p_s > 1) {
        ll p = (p_e + p_s) / 2;
        vector<ll> costs;
        rep(i, n) {
            if (p - h[i] < 0) {
                p_s = p;
                goto LOOP;
            }
            costs.emplace_back((p - h[i]) / s[i]);
        }
        sort(costs.begin(), costs.end());
        rep(i, n) {
            if (costs[i] < i) {
                p_s = p;
                goto LOOP;
            }
            if (i == n - 1) {
                p_e = p;
            }
        }
    }
    cout << p_e << endl;
}

int main() {
    cin >> n;
    h.resize(n), s.resize(n);
    rep(i, n) cin >> h[i] >> s[i];
    solve();
    return 0;
}
