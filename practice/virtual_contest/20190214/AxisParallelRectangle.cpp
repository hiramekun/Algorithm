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

ll k, n;
vector<ll> x, y;
vector<pair<ll, ll>> xy;

void solve() {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ans = (x.back() - x.front()) * (y.back() - y.front());
    rep(i, n) { // left x
        repr(j, n) { // right x
            rep(t, n) { // under y
                repr(l, n) { // top y
                    ll l_x = x[i], r_x = x[j], u_y = y[t], t_y = y[l];
                    int c = 0;
                    rep(s, n) {
                        if (l_x <= xy[s].first && xy[s].first <= r_x && u_y <= xy[s].second &&
                            xy[s].second <= t_y) {
                            c++;
                        }
                    }
                    if (c >= k) ans = min((r_x - l_x) * (t_y - u_y), ans);
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    cin >> n >> k;
    x.resize(n), y.resize(n);
    xy.resize(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
        xy[i] = make_pair(x[i], y[i]);
    }
    solve();
    return 0;
}
