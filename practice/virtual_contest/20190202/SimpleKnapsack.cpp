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

ll n, W;
vector<ll> w, v;

void solve() {
    vector<ll> w0, w1, w2, w3;
    rep(i, n) {
        if (w[i] == w[0]) w0.emplace_back(v[i]);
        else if (w[i] == w[0] + 1) w1.emplace_back(v[i]);
        else if (w[i] == w[0] + 2) w2.emplace_back(v[i]);
        else if (w[i] == w[0] + 3) w3.emplace_back(v[i]);
    }
    sort(w0.begin(), w0.end(), greater<>());
    sort(w1.begin(), w1.end(), greater<>());
    sort(w2.begin(), w2.end(), greater<>());
    sort(w3.begin(), w3.end(), greater<>());
    vector<ll> dp0(w0.size()), dp1(w1.size()), dp2(w2.size()), dp3(w3.size());
    rep(i, dp0.size())dp0[i] = i == 0 ? w0[i] : dp0[i - 1] + w0[i];
    rep(i, dp1.size())dp1[i] = i == 0 ? w1[i] : dp1[i - 1] + w1[i];
    rep(i, dp2.size())dp2[i] = i == 0 ? w2[i] : dp2[i - 1] + w2[i];
    rep(i, dp3.size())dp3[i] = i == 0 ? w3[i] : dp3[i - 1] + w3[i];
    dp0.insert(dp0.begin(), 0);
    dp1.insert(dp1.begin(), 0);
    dp2.insert(dp2.begin(), 0);
    dp3.insert(dp3.begin(), 0);

    ll ans = 0;
    rep(i, w0.size() + 1) {
        rep(j, w1.size() + 1) {
            rep(k, w2.size() + 1) {
                rep(l, w3.size() + 1) {
                    if (i * w[0] + j * (w[0] + 1) + k * (w[0] + 2) + l * (w[0] + 3) <= W) {
                        ans = max(ans, dp0[i] + dp1[j] + dp2[k] + dp3[l]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> W;
    w.resize(n), v.resize(n);
    rep(i, n) cin >> w[i] >> v[i];
    solve();
    return 0;
}
