/**
 * Created by hiramekun at 01:31 on 2019-10-03.
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
    ll n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    auto get = [&](ll i, ll add) {
        ll ret = i + add;
        if (ret >= n) ret = ret - n;
        return ret;
    };
    rep(i, n) rep(j, n) {
            cin >> s[i][j];
        }
    ll ans = 0;
    ll a = 0;
    rep(b, n) {
        vector<vector<char>> tmp(n, vector<char>(n));
        rep(i, n) {
            rep(j, n) {
                ll ni = get(i, a), nj = get(j, b);
                tmp[ni][nj] = s[i][j];
            }
        }
        rep(i, n) {
            rep(j, n) {
                if (tmp[i][j] != tmp[j][i]) {
                    goto END;
                }
            }
            if (i == n - 1) ans++;
        }
        END:;
    }

    cout << ans * n << '\n';
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
