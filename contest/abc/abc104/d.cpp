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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        string s;
        cin >> s;
        ll dp[s.length() + 10][4];
        rep(i, s.length() + 10) rep(j, 4) dp[i][j] = 0;
        dp[0][0] = 1;
        rep(i, s.length()) {
            rep(j, 4) {
                if (s[i] == '?') dp[i + 1][j] += dp[i][j] * 3; // i番目を選ばなかった時
                else dp[i + 1][j] += dp[i][j]; // i番目を選ばなかった時
                dp[i + 1][j] %= mod;
            }
            if (s[i] == 'A' || s[i] == '?') {
                dp[i + 1][1] += dp[i][0]; // 選んだ時
                dp[i + 1][1] %= mod;
            }
            if (s[i] == 'B' || s[i] == '?') {
                dp[i + 1][2] += dp[i][1]; // 選んだ時
                dp[i + 1][2] %= mod;
            }
            if (s[i] == 'C' || s[i] == '?') {
                dp[i + 1][3] += dp[i][2]; // 選んだ時
                dp[i + 1][3] %= mod;
            }
        }

        cout << dp[s.length()][3] << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}