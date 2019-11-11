/**
 * Created by hiramekun at 20:49 on 2019-11-09.
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
const ll mod = 998244353;
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
ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = powmod(x, n / 2, mod);
        return t * t % mod;
    }
    return x * powmod(x, n - 1, mod) % mod;
}

void solve() {
    ll n;
    cin >> n;
    vl d(n);
    cin >> d;
    ll pre = -1;
    if (d[0] != 0) {
        cout << 0 << '\n';
        return;
    }
    sort(all(d));
    rep(i, n) {
        if (i > 0 && d[i]== 0) {
            cout << 0 << '\n';
            return;
        }
        if (d[i] == pre) continue;
        if (d[i] > pre + 1) {
            cout << 0 << '\n';
            return;
        }
        pre = d[i];
    }

    vl cnt(n);
    rep(i, n) cnt[d[i]]++;
    ll ans = 1;
    pre = 1;
    rep(i, n) {
        if (cnt[i] == 0) break;
        ans *= powmod(pre, cnt[i], mod);
        pre = cnt[i];
        ans %= mod;
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
