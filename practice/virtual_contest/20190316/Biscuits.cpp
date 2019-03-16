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
#include <numeric>
#include <stack>

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
typedef unordered_map<ll, ll> ump;
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


ll calc(ll ce, ll co) {
    ll tmp = co;
    if (tmp % 2 != 0) tmp--;
    ll ret = 0;
    for (ll i = 0; i <= tmp; i += 2) {
        ret += comb(co, i)[co][i];
    }
    return (1LL << ce) * ret;
}

ll calc2(ll ce, ll co) {
    ll tmp = co;
    if (tmp % 2 == 0) tmp--;
    ll ret = 0;
    for (ll i = 1; i <= tmp; i += 2) {
        ret += comb(co, i)[co][i];
    }
    return (1LL << ce) * ret;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n);
        ll ce = 0, co = 0;
        rep(i, n) {
            cin >> a[i];
            a[i] %= 2;
            if (a[i] == 0) ce++;
            else co++;
        }
        if (p == 0) {
            cout << calc(ce, co) << endl;
        } else {
            cout << calc2(ce, co) << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}