/**
 * Created by hiramekun at 23:42 on 2019-08-28.
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
    ll _a, _b;
    cin >> _a >> _b;
    _a--;
    string a = to_string(_a), b = to_string(_b);
    auto calc = [&](vector<vvl> &table, string str) -> ll {
        rep(i, str.size()) {
            ll now = str[i] - '0';
            rep(smaller, 2) {
                for (ll j = 0; j < 2; ++j) {
                    for (ll x = 0; x <= (smaller ? 9 : now); ++x) {
                        table[i + 1][smaller || x < now][j || x == 4 || x == 9] += table[i][smaller][j];
                    }
                }
            }
        }
        return table.back()[0][1] + table.back()[1][1];
    };

    vector<vvl> b_dp(b.size() + 1, vvl(2, vl(2)));
    vector<vvl> a_dp(a.size() + 1, vvl(2, vl(2)));
    b_dp[0][0][0] = a_dp[0][0][0] = 1;
    cout << calc(b_dp, b) - calc(a_dp, a) << '\n';
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

