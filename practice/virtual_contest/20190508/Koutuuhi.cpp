#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
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
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef unordered_map<string, ll> mpsl;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

string ins() {
    string x;
    cin >> x;
    return (x);
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n, q;
        cin >> n >> q;
        vl x(n), dd(n + 1); // d[i]: i番目までの累積わ
        dd[0] = 0;
        rep(i, n) {
            cin >> x[i];
            dd[i + 1] = dd[i] + x[i];
        }
        vector<P> cd(q);
        rep(i, q) cd[i] = {inl(), inl()};

        rep(i, q) {
            ll c = cd[i].F, d = cd[i].S;
            auto c_minus_d = upper_bound(all(x), c - d);
            auto c_x = upper_bound(all(x), c);
            auto c_plus_d = upper_bound(all(x), c + d);
            ll idx_low = c_minus_d - x.begin();
            ll idx_c = c_x - x.begin();
            ll idx_high = c_plus_d - x.begin();
            ll ans = 0;
            ans += (n - idx_high) * d + idx_low * d;
            ans += (idx_c - idx_low) * c - (dd[idx_c] - dd[idx_low]);
            ans += (dd[idx_high] - dd[idx_c]) - (idx_high - idx_c) * c;
            cout << ans << endl;
        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}