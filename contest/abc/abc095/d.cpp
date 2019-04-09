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
        ll n = inl(), c = inl();
        vl x(n), v(n);
        rep(i, n) x[i] = inl(), v[i] = inl();
        ll dl[n + 1], dr[n + 1];
        dl[0] = 0, dr[0] = 0;
        rep(i, n) dl[i + 1] = dl[i] + v[i];
        rep(i, n) dr[i + 1] = dr[i] + v[n - 1 - i];

        ll dp1[n + 1], dp2[n + 1];
        dp1[0] = 0, dp2[0] = 0;

        rep(i, n) {
            dp1[i + 1] = max(dp1[i], dl[i] + v[i] - x[i]);
            dp2[i + 1] = max(dp2[i], dr[i] + v[n - 1 - i] - (c - x[n - i - 1]));
        }
        ll ans = 0;
        rep(i, n + 1) {
            ans = max(ans, dp1[i] + dp2[n - i] - (i == 0 ? 0 : x[i - 1]));
            ans = max(ans, dp1[i] + dp2[n - i] - (i == n ? 0 : (c - x[i])));
        }
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
};
