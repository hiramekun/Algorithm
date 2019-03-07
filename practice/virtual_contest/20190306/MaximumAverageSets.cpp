#include <cstring>
#include <sstream>
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
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<double, ll> ump;
typedef pair<ll, ll> P;

ump mp;

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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        int n, a, b;
        cin >> n >> a >> b;
        vector<double> v(n);
        rep(i, n) {
            cin >> v[i];
            mp[v[i]]++;
        }
        sort(v.begin(), v.end(), greater<>());
        cout << fixed << accumulate(v.begin(), v.begin() + a, 0.0) / a << endl;
        if (v[a - 1] == v[a]) {
            if (v[0] == v[a]) {
                ll ans = 0;
                for (int i = a; i <= min(int(mp[v[0]]), b); ++i) {
                    ans += comb(mp[v[0]], i)[mp[v[0]]][i];
                }
                cout << ans << endl;
            } else {
                int s = 0;
                rep(i, a) {
                    if (v[i] == v[a - 1]) break;
                    s++;
                }
                cout << comb(mp[v[a - 1]], a - s)[mp[v[a - 1]]][a - s] << endl;
            }

        } else {
            cout << 1 << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}