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
        ll N = inl(), W = inl();
        vl w(N), v(N);
        vvl wv(4);
        vl w_ac(4);
        rep(i, N) {
            cin >> w[i] >> v[i];
            if (i == 0) wv[0].eb(v[0]), w_ac[0] = w[0];
            else {
                wv[w[i] - w[0]].eb(v[i]);
                w_ac[w[i] - w[0]] = w[i];
            }
        }
        rep(i, 4) sort(all(wv[i]), greater<>());
        vvl dp(4);
        rep(i, 4) {
            dp[i].eb(0);
            repone(j, wv[i].size()) {
                dp[i].eb(dp[i][j - 1] + wv[i][j - 1]);
            }
        }

        ll ans = 0;
        rep(i, wv[0].size() + 1) {
            rep(j, wv[1].size() + 1) {
                rep(k, wv[2].size() + 1) {
                    rep(l, wv[3].size() + 1) {
                        if (i * w_ac[0] + j * w_ac[1] + k * w_ac[2] + l * w_ac[3] > W) continue;
                        ans = max(ans, dp[0][i] + dp[1][j] + dp[2][k] + dp[3][l]);
                    }
                }
            }
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}