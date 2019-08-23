/**
 * Created by hiramekun at 14:10 on 2019-08-23.
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {
    ll a, b;
    cin >> a >> b;

    vl button{10, 5, 1};
    ll res = ll_inf;

    auto rec = [&](auto &&f, ll idx, ll val, ll ans) -> void {
        if (val == 0) {
            res = min(res, ans);
            return;
        }
        if (idx >= button.size()) {
            return;
        }

        if (val < 0) val = -val;
        f(f, idx + 1, val % button[idx] - button[idx], ans + val / button[idx] + 1);
        f(f, idx + 1, val % button[idx], ans + val / button[idx]);
    };

    rec(rec, 0, abs(a - b), 0);
    cout << res << '\n';
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
