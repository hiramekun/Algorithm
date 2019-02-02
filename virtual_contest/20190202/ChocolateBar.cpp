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

ll h, w;

void solve() {
    ll ans = ll_inf;
    if (h % 3 == 0 || w % 3 == 0) ans = 0;
    else {
        ll a = h / 3, b = ll(ceil(double(h) / 3)), c = h - a - b;
        ans = min(ans,
                  max({a * w, b * w, c * w}) -
                  min({a * w, b * w, c * w}));
        a = w / 3, b = ll(ceil(double(w) / 3)), c = w - a - b;
        ans = min(ans,
                  max({a * h, b * h, c * h}) -
                  min({a * h, b * h, c * h}));

        repone(i, w - 1) {
            ans = min(ans,
                      max({h * i, ll(ceil(double(h) / 2) * (w - i)), (h / 2) * (w - i)}) -
                      min({h * i, ll(ceil(double(h) / 2) * (w - i)), (h / 2) * (w - i)}));
        }
        repone(i, h - 1) {
            ans = min(ans,
                      max({w * i, ll(ceil(double(w) / 2) * (h - i)), (w / 2) * (h - i)}) -
                      min({w * i, ll(ceil(double(w) / 2) * (h - i)), (w / 2) * (h - i)}));
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> h >> w;
    solve();
    return 0;
}
