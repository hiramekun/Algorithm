/**
 * Created by hiramekun at 19:43 on 2019-10-25.
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

// ceil(x/y)
ll my_ceil(ll x, ll y) {
    return ll(ceil(double(x) / y));
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {
    ll k;
    cin >> k;
    vl a(k);
    cin >> a;
    reverse(all(a));

    ll low = 2, high = 2;
    for (ll i = 0; i < k; ++i) {
        low = my_ceil(low, a[i]) * a[i];
        high = (high / a[i]) * a[i];
        // low と high の間に約数が存在するか？
        if (low > high) {
            cout << -1 << '\n';
            return;
        }
        high += a[i] - 1;
    }
    cout << low << ' ' << high << '\n';
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
