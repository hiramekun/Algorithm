/**
 * Created by hiramekun at 20:55 on 2019-09-07.
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
    vl p(n);
    unordered_map<ll, ll> mp;
    set<ll> s;
    rep(i, n) {
        cin >> p[i];
        mp[p[i]] = i;
        s.insert(p[i]);
    }

    set<ll> idx;
    ll ans = 0;
    while (!s.empty()) {
        ll now = *s.rbegin();
        s.erase(now);

        ll i = mp[now];
        vl l(2, -1), r(2, n);
        {
            auto itr = idx.lower_bound(i);
            // r
            rep(j, 2) {
                if (itr == idx.end()) break;
                r[j] = *itr;
                itr++;
            }
        }
        {
            auto itr = idx.lower_bound(i);
            rep(j, 2) {
                if (itr == idx.begin()) break;
                itr--;
                l[j] = *itr;
            }
        }

        ll l1 = i - l[0], l2 = l[0] - l[1];
        ll r1 = r[0] - i, r2 = r[1] - r[0];
        ans += (l1 * r2 + l2 * r1) * now;

        idx.insert(i);
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
