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


int n = 0, max_h = 0;
vector<int> h;

void solve() {
    ll ans = 0;
    while (max_h != 0) {
        int max_h_n = 0;
        rep(i, h.size()) {
            bool has_h = false;
            while (i < h.size() && h[i] == max_h) {
                has_h = true;
                h[i]--;
                max_h_n = max(h[i], max_h_n);
                i++;
            }
            max_h_n = max(h[i], max_h_n);
            if (has_h) ans++;
        }
        max_h = max_h_n;
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    h.resize(n);
    rep(i, n) {
        cin >> h[i];
        max_h = max(h[i], max_h);
    }
    solve();
    return 0;
}
