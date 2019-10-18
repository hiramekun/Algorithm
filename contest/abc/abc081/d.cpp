/**
 * Created by hiramekun at 09:16 on 2019-10-18.
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
    vl a(n);
    cin >> a;

    auto mima = minmax_element(all(a));
    ll mi = *mima.F, ma = *mima.S;
    if (mi >= 0) {
        cout << n - 1 << '\n';
        rep(i, n - 1) {
            cout << i + 1 << ' ' << i + 2 << '\n';
        }
    } else if (ma <= 0) {
        cout << n - 1 << '\n';
        repr(i, n - 1) {
            cout << i + 2 << ' ' << i + 1 << '\n';
        }
    } else {
        cout << 2 * n - 1 << '\n';
        if (abs(mi) > abs(ma)) {
            ll i_mi = mima.F - a.begin();
            rep(i, n) {
                cout << i_mi + 1 << ' ' << i + 1 << '\n';
            }
            repr(i, n - 1) {
                cout << i + 2 << ' ' << i + 1 << '\n';
            }
        } else {
            ll i_ma = mima.S - a.begin();
            rep(i, n) {
                cout << i_ma + 1 << ' ' << i + 1 << '\n';
            }
            rep(i, n - 1) {
                cout << i + 1 << ' ' << i + 2 << '\n';
            }
        }
    }
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
