/**
 * Created by hiramekun at 21:35 on 2019-09-22.
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
    vector<P> xy(6);
    rep(i, 6) cin >> xy[i].F >> xy[i].S;

    auto covered = [](P xya1, P xya2, P xyb3, P xyb4) {
        ll xlb = max(xya1.F, xyb3.F);
        ll ylb = max(xya1.S, xyb3.S);
        ll xrt = min(xya2.F, xyb4.F);
        ll yrt = min(xya2.S, xyb4.S);

        return max(0LL, (xrt - xlb)) * max(0LL, (yrt - ylb));
    };

    auto covered_bb = [&]() {
        ll xlb = max({xy[0].F, xy[2].F, xy[4].F});
        ll ylb = max({xy[0].S, xy[2].S, xy[4].S});
        ll xrt = min({xy[1].F, xy[3].F, xy[5].F});
        ll yrt = min({xy[1].S, xy[3].S, xy[5].S});

        return max(0LL, (xrt - xlb)) * max(0LL, (yrt - ylb));
    };

    ll wb1 = covered(xy[0], xy[1], xy[2], xy[3]);
    ll wb2 = covered(xy[0], xy[1], xy[4], xy[5]);
    ll bb = covered_bb();
    ll w = (xy[1].F - xy[0].F) * (xy[1].S - xy[0].S);

    ll res = w - wb1 - wb2 + bb;
    if (res > 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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
