/**
 * Created by hiramekun at 20:10 on 2019-11-16.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
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
    ll n, t;
    cin >> n >> t;
    vector<P> ab(n);
    rep(i, n) {
        cin >> ab[i].F >> ab[i].S;
    }
    // 美味しさ大きい順
    sort(all(ab), [](P a, P b) { return a.S > b.S; });
    vvl candi(2);
    rep(i, n) {
        if (i != 0) candi[0].eb(i);
        if (i != 1) candi[1].eb(i);
    }

    ll ans = 0;
    for (ll i = 0; i < 2; i++) {
        vvl dp(n + 10, vl(t + 3001));
        vl c = candi[i];
        rep(j, n - 1) {
            rep(k, t + 1) {
                dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
                dp[j + 1][k + ab[c[j]].F] = max({dp[j + 1][k + ab[c[j]].F], dp[j][k] + ab[c[j]].S});
            }
        }
        rep(j, n) ans = max(dp[j][t - 1] + ab[i].S, ans);
    }

    cout << ans << '\n';
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
