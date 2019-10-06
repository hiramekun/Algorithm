/**
 * Created by hiramekun at 19:37 on 2019-10-06.
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
    string s;
    cin >> s;
    ll k;
    cin >> k;

    bool isOne = true;
    ll n = s.size();
    rep(i, n - 1) {
        if (s[i] != s[i + 1]) {
            isOne = false;
            break;
        }
    }

    ll halfk = ll(ceil(k / 2.0));
    ll halfn = ll(ceil(n / 2.0));

    if (isOne) {
        if (n % 2 == 0) {
            cout << n / 2 * k << '\n';
        } else {
            cout << (n - halfn) * halfk + halfn * (k - halfk) << '\n';
        }
    } else {
        if (s[0] != s.back()) {
            ll ans = 0;
            rep(i, n - 1) {
                ll cnt = 1;
                while (i + 1 < n && s[i] == s[i + 1]) {
                    cnt++;
                    i++;
                }
                ans += cnt / 2;
            }
            cout << ans * k << '\n';
        } else {
            ll l = 1, r = 1;
            ll il = 0, ir = n - 1;
            while (s[il] == s[il + 1]) {
                l++;
                il++;
            }
            while (s[ir] == s[ir - 1]) {
                r++;
                ir--;
            }

            ll ans = 0;
            rep(i, n - 1) {
                if (s[i] == s[0]) continue;
                ll cnt = 1;
                while (i + 1 < n && s[i] == s[i + 1]) {
                    cnt++;
                    i++;
                }
                ans += cnt / 2;
            }
            ans *= k;
            ans += (k - 1) * ((l + r) / 2);
            ans += l / 2;
            ans += r / 2;
            cout << ans << '\n';
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
