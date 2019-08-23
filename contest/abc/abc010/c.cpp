/**
 * Created by hiramekun at 14:24 on 2019-08-21.
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
const ll inf = ll(1e9); const ll e5 = ll(1e5);
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
    ll sx, sy, ex, ey;
    ll t, v;
    cin >> sx >> sy >> ex >> ey >> t >> v;
    ll n;
    cin >> n;

    vector<P> xy(n);
    rep(i, n) cin >> xy[i].F >> xy[i].S;

    ll cango = t * v;
    rep(i, n) {
        double x = xy[i].F, y = xy[i].S;
        double d = sqrt((x - sx) * (x - sx) + (y - sy) * (y - sy)) +
                   sqrt((x - ex) * (x - ex) + (y - ey) * (y - ey));
        if (d <= cango) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
