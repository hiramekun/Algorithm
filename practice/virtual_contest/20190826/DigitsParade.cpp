/**
 * Created by hiramekun at 19:03 on 2019-08-26.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}


template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {
    string s;
    cin >> s;

    ll n = s.size();
    vvl dp(n + 1, vl(13)); // dp[i][j]: 先頭から見てi桁目であまりがjのものの個数

    dp[0][0] = 1;
    rep(i, n) {
        if (s[i] == '?') {
            rep(j, 13) {
                rep(k, 10) {
                    ll idx = (j * 10 + k) % 13;
                    dp[i + 1][idx] += dp[i][j];
                    dp[i + 1][idx] %= mod;
                }
            }
        } else {
            ll now = s[i] - '0';
            rep(j, 13) {
                ll idx = (j * 10 + now) % 13;
                dp[i + 1][idx] += dp[i][j];
                dp[i + 1][idx] %= mod;
            }
        }
    }
    cout << dp[n][5] << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}


