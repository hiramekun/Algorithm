/**
 * Created by hiramekun at 21:53 on 2019-09-14.
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
    ll n, k;
    cin >> n >> k;

    vector<P> xy(k);
    rep(i, k) {
        ll x, y;
        cin >> x >> y;
        auto p = minmax(x, y);
        xy[i] = p;
    }
    sort(all(xy));
    vb use(k, true);
    rep(i, k - 1) if (xy[i] == xy[i + 1]) use[i + 1] = false;
    vector<P> uniXy;
    ll ans = 0;
    rep(i, k) {
        if (!use[i]) ans++;
        else uniXy.eb(xy[i]);
    }

    k = uniXy.size();

    vl useC(n + 1);
    vb used(k);
    ll x = uniXy[0].F, y = uniXy[0].S;
    useC[x] = useC[y] = 1;
    used[0] = true;

    for (ll i = 1; i < k; ++i) {
        x = uniXy[i].F, y = uniXy[i].S;
        if (useC[x] == 0 && useC[y] == 0) continue;
        if (useC[x] > 0 && useC[y] > 0) ans++;
        useC[x]++, useC[y]++;
        used[i] = true;
    }
    rep(i, k) {
        if (used[i]) continue;
        x = uniXy[i].F, y = uniXy[i].S;
        if (useC[x] > 0 && useC[y] > 0) ans++;
        useC[x]++, useC[y]++;
        used[i] = true;
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
