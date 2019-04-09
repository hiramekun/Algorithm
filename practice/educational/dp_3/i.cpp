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
typedef vector<double> vd;
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
        ll n = inl();
        vd p(n);
        rep(i, n) cin >> p[i];
        double dp[n + 1][n + 1]; // dp[i][j]: i枚目までで表がj枚出る確率
        rep(i, n + 1) rep(j, n + 1) dp[i][j] = 0;
        dp[0][0] = 1;
        rep(i, n) {
            rep(j, n) {
                dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
                dp[i + 1][j + 1] += dp[i][j] * p[i];
            }
        }
        double ans = 0.0;
        for (int i = n / 2 + 1; i <= n; ++i) {
            ans += dp[n][i];
        }
        cout << fixed << setprecision(10) << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}