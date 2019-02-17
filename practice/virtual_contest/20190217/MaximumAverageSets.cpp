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

ll n, a, b;
vector<ll> v;
unordered_map<ll, ll> mp;

// nCr: v[n][r]
vector<vector<ll>> comb(ll n, ll r) {
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}


void solve() {
    sort(v.begin(), v.end(), greater<>());
    double tmp = 0;
    rep(i, a) tmp += v[i];
    tmp /= a;
    cout << fixed << tmp << endl;

    if (v[0] == v[a - 1]) {
        ll ans = 0;
        vector<vector<ll>> table = comb(mp[v[0]], min(mp[v[0]], b));
        for (ll i = a; i <= min(mp[v[0]], b); i++) ans += table[mp[v[0]]][i];
        cout << ans << endl;
    } else {
        ll prev = 0;
        rep(i, a) if (v[i] != v[a - 1]) prev++;
        vector<vector<ll>> table = comb(mp[v[a - 1]], a - prev);
        cout << table[mp[v[a - 1]]][a - prev] << endl;
    }
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = unordered_map<ll, ll>();
#pragma clang diagnostic pop
#endif
        cin >> n >> a >> b;
        v.resize(n);
        rep(i, n) {
            cin >> v[i];
            mp[v[i]]++;
        }
        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}
