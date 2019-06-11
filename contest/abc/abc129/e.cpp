#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using V = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

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

/* ----------- ANSWER ----------- */
/* ------------------------------ */

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        string l = ins();
        int n = l.size();
        vvl dp(n + 1, vl(2, 0));
        // dp[i][j]: i桁目まで見た時の満たす物の数
        // j = 0: 桁が一致している
        // j = 1: L以下であることが確定
        dp[0][0] = 1;

        rep(i, n) {
            { // a + b = 0;
                if (l[i] == '0') {
                    dp[i + 1][0] += dp[i][0];
                    dp[i + 1][1] += dp[i][1];
                } else {
                    dp[i + 1][1] += ((dp[i][0] + dp[i][1]) % mod);
                }
            }
            { // a + b = 1;
                if (l[i] == '0') {
                    dp[i + 1][1] += (dp[i][1] * 2 % mod);
                } else {
                    dp[i + 1][0] += (dp[i][0] * 2 % mod);
                    dp[i + 1][1] += (dp[i][1] * 2 % mod);
                }
            }
        }

        cout << (dp[n][0] + dp[n][1]) % mod << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}