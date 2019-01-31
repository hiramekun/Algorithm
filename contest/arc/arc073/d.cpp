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


ll N, W;
vector<ll> w, v;

void solve() {
    vector<ll> v0;
    vector<ll> v1;
    vector<ll> v2;
    vector<ll> v3;
    rep(i, N) {
        if (w[i] == w[0]) v0.emplace_back(v[i]);
        if (w[i] == w[0] + 1) v1.emplace_back(v[i]);
        if (w[i] == w[0] + 2) v2.emplace_back(v[i]);
        if (w[i] == w[0] + 3) v3.emplace_back(v[i]);
    }
    sort(v0.begin(), v0.end(), greater<>());
    sort(v1.begin(), v1.end(), greater<>());
    sort(v2.begin(), v2.end(), greater<>());
    sort(v3.begin(), v3.end(), greater<>());
    rep(i, v0.size() - 1) v0[i + 1] += v0[i];
    rep(i, v1.size() - 1) v1[i + 1] += v1[i];
    rep(i, v2.size() - 1) v2[i + 1] += v2[i];
    rep(i, v3.size() - 1) v3[i + 1] += v3[i];
    v0.insert(v0.begin(), 0);
    v1.insert(v1.begin(), 0);
    v2.insert(v2.begin(), 0);
    v3.insert(v3.begin(), 0);

    ll ans = 0;
    rep(i, v0.size()) {
        rep(j, v1.size()) {
            rep(k, v2.size()) {
                rep(l, v3.size()) {
                    if (w[0] * i + (w[0] + 1) * j + (w[0] + 2) * k + (w[0] + 3) * l <= W) {
                        ans = max(ans, v0[i] + v1[j] + v2[k] + v3[l]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> W;
    w.resize(N), v.resize(N);
    rep(i, N) cin >> w[i] >> v[i];
    solve();
    return 0;
}
