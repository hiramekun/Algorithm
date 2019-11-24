/**
 * Created by hiramekun at 08:21 on 2019-11-24.
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
    ll h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<ll>> ans(h, vector<ll>(w));
    vector<ll> s_idx;
    rep(i, k) s_idx.emplace_back(i + 1);

    auto dfs = [&](auto &&f, ll l, ll r, ll u, ll d, ll num) {
        if (l < 0 || w < r || u < 0 || h < d) return;
        if (r <= l || d <= u) return;
        ll prev_i = -1, prev_j = -1;
        for (ll i = u; i < d; ++i) {
            for (ll j = l; j < r; ++j) {
                if (s[i][j] != '#') continue;
                if (prev_i == -1) {
                    prev_i = i, prev_j = j;
                    continue;
                }

                ll next = s_idx.back();
                s_idx.pop_back();
                if (i != prev_i) { // 縦に分ける
                    f(f, l, r, u, i, num);
                    f(f, l, r, i, d, next);
                    return;
                }
                if (j != prev_j) { // 横に分ける
                    f(f, l, j, u, d, num);
                    f(f, j, r, u, d, next);
                    return;
                }
            }
        }
        for (ll i = u; i < d; ++i) {
            for (ll j = l; j < r; ++j) {
                ans[i][j] = num;
            }
        }
    };
    ll num = s_idx.back();
    s_idx.pop_back();
    dfs(dfs, 0, w, 0, h, num);
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
