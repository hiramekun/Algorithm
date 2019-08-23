/**
 * Created by hiramekun at 16:13 on 2019-08-23.
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
// v: 頂点数, d: 頂点間距離
vvl d(50, vl(50, ll_inf));

void warshall_floyd(ll v) {
    rep(k, v)rep(i, v)rep(j, v) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
    ll a, b;
    cin >> a >> b;
    rep(i, 50) {
        rep(j, 50) {
            ll diff = abs(j - i);
            if (diff == 0) d[i][j] = 0;
            if (diff == 1 || diff == 5 || diff == 10) d[i][j] = 1;
        }
    }
    warshall_floyd(50);
    cout << d[a][b] << '\n';
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
