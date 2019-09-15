/**
 * Created by hiramekun at 13:42 on 2019-09-15.
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
    ll t;
    cin >> t;
    rep(_, t) {
        ll n;
        cin >> n;
        string d;
        cin >> d;

        rep(i, 10) {
            vector<char> ans(n, '3');
            ll last1 = -1, first2 = n;
            ll prev1 = -1, prev2 = -1;
            bool invalid = false;
            rep(j, n) {
                ll now = d[j] - '0';
                if ((now < i && now < prev1) || (i < now && now < prev2)) {
                    invalid = true;
                    break;
                }
                if (now < i && prev1 <= now) {
                    prev1 = now;
                    ans[j] = '1', last1 = j;
                }
                if (now > i && prev2 <= now) {
                    prev2 = now;
                    ans[j] = '2';
                    if (first2 == n) first2 = j;
                }
            }
            rep(j, n) {
                ll now = d[j] - '0';
                if (now != i) continue;
                if (j < first2) ans[j] = '2';
                else if (j > last1) ans[j] = '1';
            }

            rep(j, n) {
                if (ans[j] == '3') invalid = true;
            }
            if (!invalid) {
                cout << string(all(ans)) << '\n';
                goto END;
            }
        }
        cout << '-' << '\n';
        END:;
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
