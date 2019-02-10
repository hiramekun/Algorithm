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

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

string s, t;

void solve() {
    int max_s = 3010;
    ll dp[max_s][max_s];
    dp[0][0] = 0;
    rep(i_s, s.length()) {
        rep(i_t, t.length()) {
            if (s[i_s] == t[i_t]) {
                chmax(dp[i_s + 1][i_t + 1], dp[i_s][i_t] + 1);
            } else {
                chmax(dp[i_s + 1][i_t + 1], max(dp[i_s][i_t + 1], dp[i_s + 1][i_t]));
            }
        }
    }
    string ans;
    int i_s = s.length() - 1;
    int i_t = t.length() - 1;

    while (i_s >= 0 && i_t >= 0) {
        if (dp[i_s + 1][i_t + 1] > max(dp[i_s][i_t + 1], dp[i_s + 1][i_t])) {
            ans = s[i_s] + ans;
            i_s--, i_t--;
        } else {
            if (dp[i_s + 1][i_t + 1] == dp[i_s][i_t + 1]) i_s--;
            else i_t--;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> s >> t;
    solve();
    return 0;
}
