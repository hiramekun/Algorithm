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

ll n, p;
vector<ll> a;


vector<vector<ll>> comb(int n, int r) {
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
    vector<ll> e, o;
    rep(i, n) if (a[i] % 2 == 0)e.emplace_back(a[i]); else o.emplace_back(a[i]);
    ll o_temp = 0;
    repone(i, o.size()) {
        if (i % 2 == 1) {
            if (i == o.size())o_temp++;
            else o_temp += comb(o.size(), i)[o.size()][i];
        }
    }
    if (p == 0) cout << ll(pow(ll(2), n)) - ll(pow(ll(2), ll(e.size()))) * o_temp << endl;
    else cout << ll(pow(ll(2), ll(e.size()))) * o_temp << endl;
}

int main() {
    cin >> n >> p;
    a.resize(n);
    rep(i, n) cin >> a[i];
    solve();
    return 0;
}
