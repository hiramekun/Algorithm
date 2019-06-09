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
        ll h, w;
        cin >> h >> w;

        char s[h][w];
        ll yoko_dp[h][w];
        ll tate_dp[h][w];
        rep(i, h) rep(j, w) {
                cin >> s[i][j];
                yoko_dp[i][j] = 0;
                tate_dp[i][j] = 0;
            }

        rep(i, h) rep(j, w) {
                if (s[i][j] == '#') continue;
                if (j == 0) yoko_dp[i][j] = 1;
                else yoko_dp[i][j] = yoko_dp[i][j - 1] + 1;
            }
        rep(i, w) rep(j, h) {
                if (s[j][i] == '#') continue;
                if (j == 0) tate_dp[j][i] = 1;
                else tate_dp[j][i] = tate_dp[j - 1][i] + 1;
            }

        ll yoko_max[h][w];
        repr(i, h) repr(j, w) {
                if (s[i][j] == '#') yoko_max[i][j] = 0;
                else {
                    if (j == w - 1 || yoko_dp[i][j + 1] == 0) yoko_max[i][j] = yoko_dp[i][j];
                    else yoko_max[i][j] = yoko_max[i][j + 1];
                }
            }
        ll tate_max[h][w];
        repr(i, w) repr(j, h) {
                if (s[j][i] == '#') tate_max[j][i] = 0;
                else {
                    if (j == h - 1 || tate_dp[j + 1][i] == 0) tate_max[j][i] = tate_dp[j][i];
                    else tate_max[j][i] = tate_max[j + 1][i];
                }
            }

        ll ans = 0;
        rep(i, h) rep(j, w) {
                if (s[i][j] == '#') continue;
                ans = max(ans, tate_max[i][j] + yoko_max[i][j] - 1);
            }
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}