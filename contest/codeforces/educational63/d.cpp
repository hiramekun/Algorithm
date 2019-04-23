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


ll dp[3 * half_inf + 10][4];

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n = inl(), x = inl();
        vl a(n);
        rep(i, n) cin >> a[i];

        const int plus = 0, multi = 1, no = 2, al_multi = 3;
        for (int i = 0; i < n; ++i) {
            dp[i + 1][al_multi] = max({dp[i][multi] + a[i], dp[i][al_multi] + a[i]});
            dp[i + 1][plus] = max({dp[i][plus] + a[i], dp[i][no] + a[i]});
            dp[i + 1][multi] = max({dp[i][multi] + x * a[i],
                                    dp[i][no] + x * a[i],
                                    dp[i][plus] + x * a[i]
                                   });
            dp[i + 1][no] = 0;
        }
        ll ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 4; ++j) {
                ans = max(dp[i][j], ans);
            }
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}